**Projeto:** carro autônomo, guiado por sensores ultrassônicos, com o objetivo de percorrer uma pista com laterais (superiores a altura do veículo) para que possa ter uma orientação.

**Programação:** Arduino IDE

**Prototipagem:** Arduino UNO

**Componentes:**
 - 1 Arduino UNO;
 - 3 Sensores Ultrassônicos (HC-SR04);
 - 1 Servo Motor (SG90) - 180º;
 - 3 LEDs (verdes);
 - 1 LED (azul);
 - 2 Motores DC 3-6V (com Caixa de Redução, Eixo Duplo e rodas);
 - 1 Ponte H L298N;
 - 1 Chave liga/desliga (2 posições);
 - 1 Chave liga/desliga (3 posições);
 - 1 Push button;
 - 2 Suportes para 4 Pilhas Aaa Canoa;
 - 1 Conector de Bateria 9V para P4 (macho);
 - 1 Conector rabicho P4 (fêmea);
 - Materiais eletrônicos e diversos (placas PCBs, bornes, cabos, tubos termo retráteis, solda, etc);

**Energização:**
A alimentação do Arduino e da Ponte H foram realizadas de forma independentes, para que os motores não tenham perda de corrente e afete seu desempenho.
  - Para o arduino, utilizado o plug de bateria 9V, intermediado por chave de 2 posições;
  - Para a ponte H, utilizado os 2 suportes de pilhas AAA, intermediados por chave de 3 posições, podendo ser alternado entre 6 e 12V;

**Funcionamento:**
Dois sensores ultrassônicos, cada um posicionado para um lado, realizam as medições laterais servindo para auxiliar e ajustá-lo ao centro da pista.
O sensor central fica variando sua posição através de uma movimentação contínua e repetitiva, realizada pelo servo motor. Ajustado para uma angulação próxima de 120º, o sensor frontal identifica se há e qual a proximidade do carro em relação à alguma curva e/ou borda.
Tendo as medidas coletadas pelos sensores, mediadas por condições, são feitas tomadas de decisões para que o carro siga em frente, faça curva, dê ré ou até mesmo faça rotações em torno do próprio eixo, através de instruções comandadas pela Ponte H.
LEDs foram utilizados para realizar a Human Interface Machine (HIM) - interface homem máquina -, e então permite que o usuário possa ter um guia visual de qual *sensor possui menor distância* em relação a alguma borda (indicação feita pelos LEDs verdes).
Dê início, ao ligar as chaves (Arduino e Ponte H), o programa leva 10 segundos para fazer uma varredura consistente sobre as informações iniciais (distâncias), durante este tempo, o LED (azul) fica piscando para informar que o código está em período de inicialização. Após esse tempo, o led estabiliza, deixando indicado que o usuário pode iniciar o percurso, podendo ser *"startado"* ao clique do push button.
O push button, após acionado, se pressionado outras vezes, alterna o código entre *"PLAY"* e *"PAUSE"*.
