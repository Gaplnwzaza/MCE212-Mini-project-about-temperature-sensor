float Vr, VNTC;
float a = 0.0004, b = 0.0175, c = 0.3674, d, T; // V-T from Resistor which series to Thermistor : y = 0.0004x^2 + 0.0175x + 0.3674

void setup() {
  pinMode(A2, INPUT);
  Serial.begin(9600);
}

void loop() {
  VNTC = analogRead(A2);
  Vr = 5 - (VNTC * 5/1023); //Voltage divider from 5V DC source
  d = sqrt(b * b - 4 * a * (c-Vr)); // quadratic eq formula
  T = (-b + d) / (2 * a);
  Serial.print("AnalogV = ");
  Serial.print(VNTC, 3);
  Serial.print(" , Voltage = ");
  Serial.print(Vr, 3);
  Serial.print(" V , Temperature = ");
  Serial.print(T, 3);
  Serial.println(" °C ");
  delay(500);

}
