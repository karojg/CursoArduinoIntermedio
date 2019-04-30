struct node {
  //pointer to action function, returns new state
  uint8_t (*actionDef)();//pointer to action function
};

//State Machine Objet

class TStateMachine {
  public:
    uint8_t currentState = 0; //state of thee machine
    node *nodeSet; //array where actions are stored
 
  //object constructor with n states 
  TStateMachine(uint8_t n) {
      nodeSet = new node[n];//creates the list of functions
    }

  //function to associate state and functions
  void add(uint8_t i,  uint8_t f()) {
      nodeSet[i].actionDef = f;
    }
  
   //function thata executes current state functions
   uint8_t execute() {
      currentState = nodeSet[currentState].actionDef();
      return currentState;
    }
};

/**** MAIN CODE ***/
#include <Servo.h>

TStateMachine StateMachine(2);
int state =0;
boolean boton = false;
Servo myservo;


int in(){
  if(boton) return 1;
  else {
    myservo.write(0);
    return 0;
  }
}

int out(){
  if(boton) return 0;
  else {
    myservo.write(180);
    return 1;
  }
}


void setup() {
  // put your setup code here, to run once:
  pinMode(12,INPUT_PULLUP);
  myservo.attach(6);

  StateMachine.add(0,&in);
  StateMachine.add(1,&out);
}

void loop() {
  boton = digitalRead(12);
  StateMachine.execute();
  delay(100);

}
