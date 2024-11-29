
void rotateSlave() {
  if (!slave_inv) {
    slave_pos += 2;
  } else {
    slave_pos -= 2;
  }

  if (slave_pos < 92) {
    if (dcenter > 0 && dcenter < dcenter_min_right) {
      dcenter_min_right = dcenter;
    }
  } else if (slave_pos > 92) {
    if (dcenter > 0 && dcenter < dcenter_min_left) {
      dcenter_min_left = dcenter;
    }
  } else if (slave_pos == 92) {
    if (dcenter > 0 && dcenter < dcenter_min_center) {
      dcenter_min_center = dcenter;
    }
  }

  if (slave_pos >= slave_max || slave_pos <= slave_min) slave_inv = !slave_inv;

  slave.write(slave_pos);
}

void clearCenters(){
  dcenter_min_center = 0;
    dcenter_min_right = 0;
    dcenter_min_left = 0;
}