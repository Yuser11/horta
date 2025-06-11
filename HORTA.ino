#include <OneWire.h>
#include <DallasTemperature.h>
#define PINO_SENSOR 4
OneWire barramento(PINO_SENSOR);
DallasTemperature sensor(&barramento);
int luminosidade;
void setup() {
  sensor.begin();
  Serial.begin(115200);
}

void loop() {
  // Pede para o sensor fazer a leitura
  sensor.requestTemperatures();

  // Pega o valor da temperatura em Celsius
  float temperaturaC = sensor.getTempCByIndex(0);

  // Pega o valor da temperatura em Fahrenheit
  float temperaturaF = sensor.getTempFByIndex(0);

  // Mostra as informações no monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperaturaC);
  Serial.print(" °C  |  ");
  Serial.print(temperaturaF);
  Serial.println(" °F");
  Serial.println(luminosidade);
  if (Serial.available())
  {
    luminosidade = (Serial.readString().toInt());
  }
  // Espera 1 segundo para nova leitura
  delay(1000);
}
