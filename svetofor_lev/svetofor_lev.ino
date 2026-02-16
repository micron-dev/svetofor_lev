#define r1 13
#define ye1 12
#define g1 11

#define r2 10
#define ye2 9
#define g2 8

#define pR1 7
#define pG1 6

#define pR2 5
#define pG2 4

int flag = 6;
long lt;

int blinkState = 0;
int blinkCounter = 0;
long blinkTimer = 0;

void setup() {
  pinMode(r1, OUTPUT);
  pinMode(ye1, OUTPUT);
  pinMode(g1, OUTPUT);

  pinMode(r2, OUTPUT);
  pinMode(ye2, OUTPUT);
  pinMode(g2, OUTPUT);

  pinMode(pR1, OUTPUT);
  pinMode(pG1, OUTPUT);
  pinMode(pR2, OUTPUT);
  pinMode(pG2, OUTPUT);

  digitalWrite(r1, HIGH);
  digitalWrite(g2, HIGH);

  digitalWrite(pR1, HIGH);
  digitalWrite(pG1, LOW);
  digitalWrite(pR2, HIGH);
  digitalWrite(pG2, LOW);

  lt = millis();
}

void loop() {
  switch (flag) {
    case 0:
      if (millis() - blinkTimer >= 300) {
        blinkTimer = millis();

        blinkState = !blinkState;
        digitalWrite(g2, blinkState);
        blinkCounter++;
      }
      digitalWrite(pR1, HIGH);
      digitalWrite(pG1, LOW);
      digitalWrite(pR2, HIGH);
      digitalWrite(pG2, LOW);

      if (blinkCounter >= 3) {
        blinkCounter = 0;
        flag = 1;
        lt = millis();
      }
      break;

    case 1:
      digitalWrite(ye1, HIGH);
      digitalWrite(ye2, HIGH);

      digitalWrite(pR1, HIGH);
      digitalWrite(pG1, LOW);
      digitalWrite(pR2, HIGH);
      digitalWrite(pG2, LOW);
      if (millis() - lt >= 2000) {
        flag = 2;
        lt = millis();
      }
      break;

    case 2:
      digitalWrite(r1, LOW);
      digitalWrite(ye1, LOW);
      digitalWrite(g1, HIGH);

      digitalWrite(g2, LOW);
      digitalWrite(ye2, LOW);
      digitalWrite(r2, HIGH);

      digitalWrite(pR1, LOW);
      digitalWrite(pG1, HIGH);
      digitalWrite(pR2, LOW);
      digitalWrite(pG2, HIGH);
      if (millis() - lt >= 5000) {
        flag = 3;
        lt = millis();
      }
      break;

    case 3:
      if (millis() - lt >= 5000) {
        flag = 4;
        blinkState = 0;
        blinkCounter = 0;
        blinkTimer = millis();
      }
      break;

    case 4:
      if (millis() - blinkTimer >= 300) {
        blinkTimer = millis();
        blinkState = !blinkState;
        digitalWrite(pG1, blinkState);
        digitalWrite(pG2, blinkState);
        blinkCounter++;
      }

      if (blinkCounter >= 3) {
        digitalWrite(pG1, LOW);
        digitalWrite(pR1, HIGH);
        digitalWrite(pG2, LOW);
        digitalWrite(pR2, HIGH);

        digitalWrite(g1, LOW);
        digitalWrite(ye1, HIGH);

        flag = 5;
        lt = millis();
      }
      break;

    case 5:
      if (millis() - lt >= 2000) {
        digitalWrite(ye1, LOW);
        digitalWrite(r1, HIGH);
        digitalWrite(ye2, HIGH);
        flag = 6;
        lt = millis();
      }
      break;

    case 6:
      if (millis() - lt >= 2000) {
        digitalWrite(ye2, LOW);
        digitalWrite(r2, LOW);
        digitalWrite(g2, HIGH);
        flag = 7;
        lt = millis();
      }
      break;

    case 7:
      if (millis() - lt >= 2000) {
        flag = 0;
        lt = millis();
      }
      break;
  }
}