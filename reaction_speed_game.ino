// Variables
int stButton = A2;
int stVal;

int buttonPin1 = A0;
int player1Val;
int buttonPin2 = A1;
int player2Val;

int bluePin1 = 10;
int bluePin2 = 4;

// led left to right...
int red1 = 9;
int yellow1 = 8;
int green = 7;
int yellow2 = 6;
int red2 = 5;

int wait = 100;
int delayTime = 1000;
int randomVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(stButton, INPUT);

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);

  pinMode(bluePin1, OUTPUT);
  pinMode(bluePin2, OUTPUT);

  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(red2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  stVal = digitalRead(stButton);
  while(stVal == 1){
    stVal = digitalRead(stButton);
    Serial.println("Waiting");
  }

  randomVal = (random(1, 6)) * 1000;

  delay(wait);
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(yellow1, LOW);
  digitalWrite(yellow2, LOW);
  digitalWrite(green, LOW);
  delay(delayTime);
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(yellow1, HIGH);
  digitalWrite(yellow2, HIGH);
  digitalWrite(green, LOW);
  delay(delayTime);
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(yellow1, HIGH);
  digitalWrite(yellow2, HIGH);
  digitalWrite(green, HIGH);
  delay(randomVal);
  digitalWrite(red1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(yellow1, LOW);
  digitalWrite(yellow2, LOW);
  digitalWrite(green, LOW);


  player1Val = digitalRead(buttonPin1);
  player2Val = digitalRead(buttonPin2);
  Serial.print("Player1 ");
  Serial.print(player1Val);
  Serial.print(" Player2 ");
  Serial.println(player2Val);

  while (player1Val == 1 && player2Val == 1) {
    player1Val = digitalRead(buttonPin1);
    player2Val = digitalRead(buttonPin2);
    Serial.println("hello");
  }

  if (player1Val == 0) {
    player2Val = 1;
    digitalWrite(bluePin1, HIGH);
    digitalWrite(bluePin2, LOW);
  }
  if (player2Val == 0) {
    player1Val = 1;
    digitalWrite(bluePin1, LOW);
    digitalWrite(bluePin2, HIGH);
  }

  delayMicroseconds(wait);
  for (int i = 1; i <= 10; i += 1) {
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);
    delay(wait);
    digitalWrite(yellow1, HIGH);
    digitalWrite(yellow2, HIGH);
    delay(wait);
    digitalWrite(green, HIGH);
    delay(wait * 2);
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(green, LOW);
    delay(wait * 2);
  }
  delayMicroseconds(wait);
  digitalWrite(bluePin1, LOW);
  digitalWrite(bluePin2, LOW);
  delayMicroseconds(wait);
}
