int sensor_pin = A4; /* Soil moisture sensor O/P pin */

void setup() {
Serial.begin(9600); /* Define baud rate for serial communication */

}
void loop() {
    float moisture_percentage;
    int sensor_analog;
    sensor_analog = analogRead(sensor_pin);
    moisture_percentage = 100 - ( (sensor_analog/4095.00) * 100 );
    Particle.publish("Moisture1", String(sensor_analog), PRIVATE);
    Serial.print("Moisture Percentage = ");
    Serial.print(sensor_analog);
    Serial.print("%\n\n");
    delay(1000);
}

