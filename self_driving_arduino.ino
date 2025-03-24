int ENA = 10, IN1 = 9, IN2 = 8;
int ENB = 5, IN3 = 7, IN4 = 6;

int trigPin1 = A0, echoPin1 = A1; // 오른쪽
int trigPin2 = A2, echoPin2 = A3; // 왼쪽

int obstacleThreshold = 5;

void setup() {
  pinMode(ENA, OUTPUT); pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT); pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(trigPin1, OUTPUT); pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT); pinMode(echoPin2, INPUT);
  Serial.begin(9600);
}

void loop() {
  float right = getDistance(trigPin1, echoPin1);
  float left = getDistance(trigPin2, echoPin2);

  Serial.print("Right: "); Serial.print(right);
  Serial.print(" cm\tLeft: "); Serial.println(left);

  if (left < obstacleThreshold) {
    goBackward(); delay(500);
    turnRight();  delay(500);
  } else if (right < obstacleThreshold) {
    goBackward(); delay(500);
    turnLeft();   delay(500);
  } else {
    goForward();
  }

  delay(100); // 센서 재탐색 속도 조절
}

float getDistance(int trig, int echo) {
  digitalWrite(trig, LOW); delayMicroseconds(2);
  digitalWrite(trig, HIGH); delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH, 30000);
  return duration * 0.034 / 2;
}

void goForward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW); analogWrite(ENA, 200);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW); analogWrite(ENB, 200);
}

void goBackward() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH); analogWrite(ENA, 200);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH); analogWrite(ENB, 200);
}

void turnLeft() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH); analogWrite(ENA, 200);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW); analogWrite(ENB, 200);
}

void turnRight() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW); analogWrite(ENA, 200);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH); analogWrite(ENB, 200);
}
