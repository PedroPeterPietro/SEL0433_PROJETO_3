
const int RED_PIN   = 25;
const int GREEN_PIN = 26;
const int BLUE_PIN  = 27;

const int PWM_FREQ = 5000;
const int PWM_RES  = 8;


int redDuty = 0;
int greenDuty = 0;
int blueDuty = 0;


const int RED_INCREMENTO = 15;
const int GREEN_INCREMENTO = 5;
const int BLUE_INCREMENTO = 10;

void setup() {

  Serial.begin(115200);

  
  ledcAttach(RED_PIN, PWM_FREQ, PWM_RES);
  ledcAttach(GREEN_PIN, PWM_FREQ, PWM_RES);
  ledcAttach(BLUE_PIN, PWM_FREQ, PWM_RES);

  Serial.println();

}

void loop() {

  redDuty += RED_INCREMENTO;
  greenDuty += GREEN_INCREMENTO;
  blueDuty += BLUE_INCREMENTO;

  if (redDuty > 255) redDuty = 0;
  if (greenDuty > 255) greenDuty = 0;
  if (blueDuty > 255) blueDuty = 0;

  // Atualiza PWM
  ledcWrite(RED_PIN, redDuty);
  ledcWrite(GREEN_PIN, greenDuty);
  ledcWrite(BLUE_PIN, blueDuty);

  Serial.print("R: ");
  Serial.print(redDuty);

  Serial.print(" | G: ");
  Serial.print(greenDuty);

  Serial.print(" | B: ");
  Serial.println(blueDuty);

  delay(200);
}
