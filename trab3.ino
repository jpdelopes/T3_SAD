int led1 = 0;
int led2 = 1;
int ldr1 = 2;
int ldr2 = 3;
int motor1 = 9;
int motor2 = 10;
int ldr_read1 = 0;
int ldr_read2 = 0;
int tolerance = 50;

void setup() {
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void loop() {
  ldr_read1 = analogRead(ldr1);
  ldr_read2 = analogRead(ldr2);

  if (ldr_read1 > 700 && ldr_read2 > 700) {     // Maximum intensity (both leds on)
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
  }

  else  if (ldr_read1 < 200 && ldr_read2 < 200) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
  }

  else  {

    if (ldr_read1 > ldr_read2)  {                 // Rotate in one direction
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(motor2, LOW);
      digitalWrite(motor1, HIGH);
    }

    else  {                                       // Rotate opposite direction

      digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(motor1, LOW);
      digitalWrite(motor2, HIGH); 

    }

  }

  delay(100);

}
