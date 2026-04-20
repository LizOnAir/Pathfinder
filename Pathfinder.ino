int BUT1 = D0;
int BUT2 = D1;
int BUT3 = D2;
int LED1 = D3;
int LED2 = D4;
int LED3 = D5;

void setup() {
  pinMode(BUT1, INPUT_PULLUP);
  pinMode(BUT2, INPUT_PULLUP);
  pinMode(BUT3, INPUT_PULLUP);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  long startTime = millis();

}

void SequenceLightUp() {
  analogWrite(LED1, 255);
  analogWrite(LED2, 100);
  analogWrite(LED3, 50);
  
  now = millis();
  if (startTime - now) >= 10000 {
    analogWrite(LED1, --);
    analogWrite(LED2, --);
    analogWrite(LED3, --);
  }
  else if (startTime - now) >= 7000 {
    analogWrite(LED1, ++);
    analogWrite(LED2, --);
    analogWrite(LED3, --);
  }
  else if (startTime - now) >= 5000 {
    analogWrite(LED1, --);
    analogWrite(LED2, --);
    analogWrite(LED3, ++);
  }
  else {
    analogWrite(LED1, --);
    analogWrite(LED2, ++);
    analogWrite(LED3, ++);
  }

}

void loop() {
  if (digitalRead (BUT1) == HIGH) {
    but1time = millis();
    digitalWrite(LED1, HIGH);
  }
  if (digitalRead (BUT2) == HIGH) {
    but2time = millis();
    digitalWrite(LED2, HIGH);
  }
  if (digitalRead (BUT3) == HIGH) {
    but3time = millis();
    digitalWrite(LED3, HIGH);
  }

  if (abs(but2time - but1time) <= 1000) & (abs(but3time - but2time) <= 1000) {
    SequenceLightUp();
  } else {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  }

}
