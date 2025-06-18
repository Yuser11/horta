#include <OneWire.h>
#include <DallasTemperature.h>
#define PINO_SENSOR D7
OneWire barramento(PINO_SENSOR);
DallasTemperature sensor(&barramento);
int luminosidade;
int umidade;
int tempoSol=1023;
int minutosSeco=0;
int tempoSeco = 0;
unsigned long millisTarefa1 = millis();
void setup() {
  sensor.begin();
  Serial.begin(115200);
  Serial.println("Quantas horas a planta pode ficar sem água?"); 
}

void loop() {
  // Pede para o sensor fazer a leitura
  sensor.requestTemperatures();
if (Serial.available() > 0)
{
  if (tempoSeco != 0){
    tempoSeco = Serial.parseInt();
    tempoSeco *= 60;
  }
}
  umidade = analogRead(A0);
  Serial.println(umidade);
  // Pega o valor da temperatura em Celsius
  float temperaturaC = sensor.getTempCByIndex(0);

  // Pega o valor da temperatura em Fahrenheit
  float temperaturaF = sensor.getTempFByIndex(0);
  if (umidade > 1000 )
  {
    if ((millis() - millisTarefa1) < 60000) {    
  } else if (millis() - millisTarefa1 > 60000) {
    millisTarefa1 = millis();
    minutosSeco ++;
  }
  if (minutosSeco > tempoSeco){
  }
  // Mostra as informações no monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperaturaC);
  Serial.println(" °C");
  if (Serial.available())
  
  {
    luminosidade = (Serial.readString().toInt());
  }
  // Espera 1 segundo para nova leitura
  delay(1000);
}

}