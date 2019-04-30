#define LED 13

//función de flip
void flip(int pin,int *state){
  digitalWrite(pin,*state);
  *state=!(*state);
}

void setup() {
  pinMode(LED,OUTPUT);

}

void loop() {
  static int state = HIGH;
  flip(LED,&state);
  delay(300);
}
