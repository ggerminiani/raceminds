bool READING = true;
bool START = false;
unsigned long timmer_start;
unsigned long interval_start = 10000;


int slave_min = 40;
int slave_max = 145;
int slave_pos = slave_min;
bool slave_inv = false;
unsigned long timmer_slave;
unsigned long interval_slave = 10;

int min_to_reverse = 5;
int dcenter = -1;
int dcenter_min_center = 9999;
int dcenter_min_right = 9999;
int dcenter_min_left = 9999;
int dright = 0;
int dleft = 0;
unsigned long timmer_read_distance;
unsigned long interval_read_distance = 15;

int width_circ = 60;
int lanes_cicr = width_circ / 3;
int lane_long = lanes_cicr * 2;
int middle_circ = width_circ / 2;
int witdth_car = 24;
int dist_sensor = 12;
int margin_sensor = middle_circ - dist_sensor;
int dist_min_border = 5;

int next_move = -1;
bool moving = false;
int default_interval_move = 200;
unsigned long timmer_move;
unsigned long interval_move = default_interval_move;

bool led_state = false;
unsigned long timmer_led = 0;
unsigned long interval_led = 500;

bool led_start_state = false;
unsigned long timmer_led_start = 0;
unsigned long interval_led_start = 1000;