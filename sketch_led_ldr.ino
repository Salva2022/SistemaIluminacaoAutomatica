const char led_0 = 5;
const char sinal_0 = 7;
int ldr = A0; 
int valorldr = 0;

void setup() {
  pinMode(led_0, OUTPUT);
  pinMode(sinal_0, OUTPUT); 
  pinMode(ldr, INPUT);
  Serial.begin(9600);
}

void loop() {
  valorldr = analogRead(ldr);
  Serial.print("Leitura do Ldr:");
  Serial.println(valorldr);
  delay(1000);

  if ((valorldr) < 400) { 
    digitalWrite(led_0, LOW);
    digitalWrite(sinal_0, HIGH);
  }

  else {
   digitalWrite(led_0, HIGH);
   digitalWrite(sinal_0, LOW);
  }
}