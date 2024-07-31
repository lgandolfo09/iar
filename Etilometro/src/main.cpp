#include <Arduino.h>
#include <TFT_eSPI.h>
#define b1 10 // BOTON DE ENCENDIDO
#define b2 11 // BOTON DE MENU
#define ARRIBA 12
#define ABAJO 13

int a = 0;

TFT_eSPI tft = TFT_eSPI();

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("hola");
  delay(2000);
  a = 1;
  tft.begin();
  tft.setRotation(1);                  // Establecemos la rotación de la pantalla
  tft.fillScreen(TFT_BLACK);           // Establecemos el color del fondo de la pantalla
  tft.setTextColor(TFT_WHITE);         // Establecemos un tamaño de texto
  tft.drawString("Inicio", 50, 80, 4); // Imprimimos un texto en la pantalla
  pinMode(b2, INPUT);
  pinMode(b1, INPUT);
  pinMode(ARRIBA, INPUT);
  pinMode(ABAJO, INPUT);
}
void loop()
{

  // put your main code here, to run repeatedly:
  switch (a)
  {
  case 1:
    tft.fillScreen(TFT_BLACK);
    Serial.println("Precalentar");
    tft.drawString("Fecha", 10, 10, 2);
    tft.drawString("Bateria", 200, 10, 2);
    tft.drawString("Precalentar", 25, 80, 4);
    delay(2000);
    a = 2;
    break;
  case 2:
    tft.fillScreen(TFT_BLACK);
    Serial.println("Control del aparato");
    tft.drawString("Fecha", 10, 10, 2);
    tft.drawString("Bateria", 200, 10, 2);
    tft.drawString("Control del", 20, 80, 4);
    tft.drawString("aparato", 50, 110, 4);
    delay(2000);
    a = 3;
    break;
  case 3:
    tft.fillScreen(TFT_BLACK);
    Serial.println("Buen funcionamiento verificado");
    tft.drawString("Fecha", 10, 10, 2);
    tft.drawString("Bateria", 200, 10, 2);
    tft.drawString("Buen", 80, 80, 3);
    tft.drawString("funcionamiento", 5, 110, 3);
    tft.drawString("verificado", 50, 140, 3);
    delay(2000);
    tft.fillScreen(TFT_BLACK);
    Serial.println("Listoh");
    tft.drawString("Fecha", 10, 10, 2);
    tft.drawString("Bateria", 200, 10, 2);
    tft.drawString("Listo", 75, 80, 4);
    delay(500);
    a = 4;
    break;
  case 4:
    if (b1 == HIGH)
    {
      tft.fillScreen(TFT_BLACK);
      Serial.println("Control de cero");
      tft.drawString("Fecha", 10, 10, 2);
      tft.drawString("Bateria", 200, 10, 2);
      tft.drawString("Control de", 35, 80, 4);
      tft.drawString("cero", 80, 110, 4);
      delay(2000);
      a = 5;
    }
    if (b2 == HIGH)
    {
      tft.fillScreen(TFT_BLACK);
      tft.setTextColor(TFT_BLACK, TFT_WHITE);
      Serial.println("Apagar");
      tft.drawString("Apagar", 40, 50, 4);
      tft.setTextColor(TFT_WHITE);
      Serial.println("Historial");
      tft.drawString("Historial", 85, 50, 4);
      delay(500);
      a = 14;
    }
    break;
  case 5:
    tft.fillScreen(TFT_BLACK);
    Serial.println("Cero =");
    Serial.println("0.00 g/L");
    tft.drawString("Fecha", 10, 10, 2);
    tft.drawString("Bateria", 200, 10, 2);
    tft.drawString("Cero =", 60, 80, 4);
    tft.drawString("0.00 g/L", 60, 110, 4);
    delay(2000);
    a = 6;
    break;
  case 6:
    tft.fillScreen(TFT_BLACK);
    Serial.println("Soplar");
    tft.drawString("Fecha", 10, 10, 2);
    tft.drawString("Bateria", 200, 10, 2);
    tft.drawString("Soplar", 75, 80, 4);
    delay(60000);
    a = 7;
    break;
  case 7:
    tft.fillScreen(TFT_BLACK);
    Serial.println("Medición g/L");
    Serial.println("Nº de registro");
    tft.drawString("Fecha", 10, 10, 2);
    tft.drawString("Bateria", 200, 10, 2);
    tft.drawString("Medicion g/L", 20, 80, 4);
    tft.drawString("N de registro", 40, 50, 4);
    delay(2000);
    a = 8;
    break;
  case 8:
    tft.fillScreen(TFT_BLACK);
    Serial.println("Imprimiendo");
    tft.drawString("Fecha", 10, 10, 2);
    tft.drawString("Bateria", 200, 10, 2);
    tft.drawString("Imprimiendo", 40, 50, 4);
    delay(2000);
    a = 9;
    break;
  case 9:
    tft.fillScreen(TFT_BLACK);
    Serial.println("Listoh");
    tft.drawString("Fecha", 10, 10, 2);
    tft.drawString("Bateria", 200, 10, 2);
    tft.drawString("Listo", 75, 80, 4);
    delay(500);
    a = 4;
    break;
  case 10:
    tft.fillScreen(TFT_BLACK);
    Serial.println("Error de funcionamiento");
    tft.drawString("Error de funcionamiento", 40, 50, 4);
    break;
  case 11:
    if (b1 == HIGH)
    {
      tft.fillScreen(TFT_BLACK);
      Serial.println("Medicion");
      tft.drawString("Medicion", 40, 50, 4);
      delay(500);
      a = 12;
    }
    if (b2 == HIGH)
    {
      tft.fillScreen(TFT_BLACK);
      Serial.println("Listoh");
      tft.drawString("Fecha", 10, 10, 2);
      tft.drawString("Bateria", 200, 10, 2);
      tft.drawString("Listo", 75, 80, 4);
      delay(500);
      a = 4;
    }
    break;
  case 12:
    if (b1 == HIGH)
    {
      tft.fillScreen(TFT_BLACK);
      Serial.println("Imprimiendo");
      tft.drawString("Imprimiendo", 40, 50, 4);
      delay(2000);
      a = 13;
    }
    if (b2 == HIGH)
    {
      tft.fillScreen(TFT_BLACK);
      tft.setTextColor(TFT_BLACK, TFT_WHITE);
      Serial.println("Apagar");
      tft.drawString("Apagar", 40, 50, 4);
      tft.setTextColor(TFT_WHITE);
      Serial.println("Historial");
      tft.drawString("Historial", 85, 50, 4);
      delay(500);
      a = 11;
    }
    break;
  case 13:
    tft.drawString("Listo", 75, 80, 4);
    delay(500);
    a = 11;
    break;
  case 14:
    if (b1 == HIGH)
    {
      tft.fillScreen(TFT_BLACK);
    }
    if (b2 ==HIGH)
    {
      tft.fillScreen(TFT_BLACK);
      Serial.println("Listoh");
      tft.drawString("Fecha", 10, 10, 2);
      tft.drawString("Bateria", 200, 10, 2);
      tft.drawString("Listo", 75, 80, 4);
      delay(500);
      a = 4;
    }
    if (ABAJO == HIGH)
    {
      tft.fillScreen(TFT_BLACK);
      tft.setTextColor(TFT_WHITE);
      Serial.println("Apagar");
      tft.drawString("Apagar", 40, 50, 4);
      tft.setTextColor(TFT_BLACK, TFT_WHITE);
      Serial.println("Historial");
      tft.drawString("Historial", 85, 50, 4);
      delay(500);
      a = 15;
    }
    break;
  case 15:
  if(b1==HIGH){
    tft.fillScreen(TFT_BLACK);
      Serial.println("Medicion");
      tft.drawString("Medicion", 40, 50, 4);
      delay(500);
    a = 12;
  }
    if (b2 == HIGH)
    {
      tft.fillScreen(TFT_BLACK);
      Serial.println("Listoh");
      tft.drawString("Fecha", 10, 10, 2);
      tft.drawString("Bateria", 200, 10, 2);
      tft.drawString("Listo", 75, 80, 4);
      delay(500);
      a = 4;
    }
    if (ARRIBA == HIGH)
    {
      tft.fillScreen(TFT_BLACK);
      tft.setTextColor(TFT_BLACK, TFT_WHITE);
      Serial.println("Apagar");
      tft.drawString("Apagar", 40, 50, 4);
      tft.setTextColor(TFT_WHITE);
      Serial.println("Historial");
      tft.drawString("Historial", 85, 50, 4);
      delay(500);
      a = 14;
    }
    break;
  }
}