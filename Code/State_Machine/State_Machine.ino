struct node{
  int (*actionDef)();
};


class TStateMachine{
  public:
  int currentState =0;
  node *nodeSet;

  TStateMachine(int n){
    nodeSet = new node[n];
  }


  void add(int state, int f()){
    nodeSet[state].actionDef = f; 
  }

  int execute(){
    currentState=nodeSet[currentState].actionDef();
    return currentState;
  }
  
};

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
