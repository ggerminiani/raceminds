
void distanceRead() {

  if (millis() - timmer_read_distance > interval_read_distance) {
    timmer_read_distance = millis();
    dcenter = us_center.distance();
    dright = us_right.distance();
    dleft = us_left.distance();
    rotateSlave();
    showLED();
  }
}


void distanceShow() {
  Serial.println("");
  Serial.println("DISTANCE CENTER: " + String(dcenter));
  Serial.println("DISTANCE CENTER [RIGHT]: " + String(dcenter_min_right));
  Serial.println("DISTANCE CENTER [LEFT ]: " + String(dcenter_min_left));
  Serial.println("DISTANCE RIGHT: " + String(dright));
  Serial.println("DISTANCE LEFT: " + String(dleft));
  Serial.println("____________________________________________");
}

void nextMove() {
  if (millis() - timmer_move <= interval_move) {
    Serial.println("NEXT MOVE: " + String(next_move));

    switch (next_move) {
      case -1:
        motor_stop();
        break;
      case 0:
        motor_foward();
        break;
      case 1:
        motor_right();
        break;
      case 2:
        motor_left();
        break;
      case 3:
        motor_reverse();
        break;
      case 4:
        motor_rot_right();
        break;
      case 5:
        motor_rot_left();
        break;
      default:
        motor_stop();
        break;
    }
  } else {
    moving = false;
    motor_stop();
  }
}

void decision() {

  if (!moving) {

    Serial.println("decision");
    moving = true;
    timmer_move = millis();
    next_move = 0;
    interval_move = default_interval_move;
    analyses(false);
  }
}

void analyses(bool show_serial) {

  if (show_serial) distanceShow();

  //LATERAIS PROXIMA A DISTANCIA DE SEGURANÇA
  if (dright <= dist_min_border + 4 || dleft <= dist_min_border + 4) {
    if (show_serial) Serial.println("LATERAIS PROXIMA A DISTANCIA DE SEGURANCA");

    if (dright <= dist_min_border + 4 && dleft >= lanes_cicr) {
      if (show_serial) Serial.println("DIREITA <= MENOR QUE DIST DE SEGURANCA + ESQUERDA >= MEIO CIRC");
      next_move = 2;
    } else if (dleft <= dist_min_border + 4 && dright >= lanes_cicr) {
      if (show_serial) Serial.println("ESQUERDA <= MENOR QUE DIST DE SEGURANCA + DIREITA >= MEIO CIRC");
      next_move = 1;
    }

    interval_move = 200;
    return;
  }

  //CORREDOR - REVER
  if (dright <= middle_circ && dleft <= middle_circ && dcenter_min_right >= width_circ && dcenter_min_left >= width_circ) {
    if ((dright - dleft) > 0) {
      if (show_serial) Serial.println("DIREITA <= MENOR QUE DIST DE SEGURANCA + ESQUERDA >= MEIO CIRC");
      next_move = 2;
    }
    if ((dright - dleft) < 0) {
      next_move = 1;
    }

    interval_move = 200;
    return;
  }


  //LATERAIS COM DISTANCIA SUPERIOR A LARGURA DO CIRCUITO
  if (dright > width_circ && dleft > width_circ) {
    if (show_serial) Serial.println("LATERAIS COM DISTANCIA SUPERIOR A LARGURA DO CIRCUITO");

    //CENTROS MENORES QUE DIST SEG
    if (dcenter_min_right <= dist_min_border || dcenter_min_left <= dist_min_border) {
      if (show_serial) Serial.println("CENTRO (DIREITA OU ESQUERA) <= DIST SEG");

      if (dcenter_min_right < dcenter_min_left) {
        if (show_serial) Serial.println("CENTRO DIREITA < CENTRO ESQUERDA");
        next_move = 5;
      }

      if (dcenter_min_right > dcenter_min_left) {
        if (show_serial) Serial.println("CENTRO DIREITA > CENTRO ESQUERDA");
        next_move = 4;
      }

      //TODO - CENTRO[CENTRO]


      interval_move = 200;
      return;
    }
  }


  //LATERAIS COM DISTANCIA SUPERIOR A DIST SEG
  if (dright > dist_min_border && dleft > dist_min_border) {

    if (dcenter_min_center > dist_min_border && dcenter_min_right > dist_min_border && dcenter_min_left > dist_min_border) {

      if (dcenter_min_center <= middle_circ && dcenter_min_right <= middle_circ && dcenter_min_left <= middle_circ) {
        if (dleft > width_circ || dright > width_circ) {
          if (show_serial) Serial.println("ALGUMA LATERAL > TAMANHO CIRC");
          if (dleft > dright) {
            next_move = 5;
          } else {
            next_move = 4;
          }
          interval_move = 300;
          return;
        }
      }


      if (show_serial) Serial.println("CENTROS > DIST SEG");
      next_move = 0;
      return;
    }
  }

  //CENTROS <= MEIO DA PISTA (CURVA)
  if (dcenter_min_right <= middle_circ || dcenter_min_left <= middle_circ) {

    if (dcenter_min_right <= middle_circ && dleft > width_circ) {
      if (show_serial) Serial.println("CENTRO[RIGHT] < CENTRO PISTA && ESQUERDA > LARGURA CIRCUITO");
      next_move = 2;
    }

    if (dcenter_min_left <= middle_circ && dright > width_circ) {
      if (show_serial) Serial.println("CENTRO[LEFT] < CENTRO PISTA && DIREITA > LARGURA CIRCUITO");
      next_move = 1;
    }

    interval_move = 300;
    return;
  }

  //TODAS A MEDIDAS <= LARGURA DO CIRCUITO
  if (
    dcenter_min_center <= width_circ && dcenter_min_right <= width_circ && dcenter_min_left <= width_circ && dleft <= width_circ && dright <= width_circ) {
    if (show_serial) Serial.println("TODAS A MEDIDAS <= LARGURA DO CIRCUITO");
    next_move = 0;
  }

  //ALGUMA DISTANCIA <= 5 E > 0
  if ((dcenter_min_center <= min_to_reverse && dcenter_min_center > 0)
      || (dcenter_min_right <= min_to_reverse && dcenter_min_right > 0)
      || (dcenter_min_left <= min_to_reverse && dcenter_min_left <= min_to_reverse)
      || (dleft <= min_to_reverse && dleft > 0)
      || dright <= min_to_reverse && dright > 0) {
    if (show_serial) Serial.println("ALGUMA DISTANCIA <= 5 E > 0");
    next_move = 3;
    interval_move = 400;
    //clearCenters();
    return;
  }
}
