struct punto2D {
  int x, y;
};

punto2D mypunto;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop() {
  mypunto.x = analogRead(A0);
  mypunto.y = analogRead(A1);
}
