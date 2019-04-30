class TLed{
  bool isOn= false;
  int p = 13;
  
  public:
  TLed(int pin){
    p  = pin;
    pinMode(p, OUTPUT);
  }
  
  void turnOn(){
    isOn=true;
    digitalWrite(p,HIGH);
  }
  
  void turnOff(){
    isOn=false;
    digitalWrite(p,LOW);
  } 
};

TLed myled(13);

void setup()
{
  
}

void loop()
{
  myled.flip();
  delay(300); // Wait for 1000 millisecond(s)
  // turn the LED off by making the voltage LOW
  myled.flip();
  delay(300); // Wait for 1000 millisecond(s)
}
