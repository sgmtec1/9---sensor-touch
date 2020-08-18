// Open Source
#include <Wire.h> //INCLUSÃO DE BIBLIOTECA
#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
int pinoAnalogico = A0; //PINO ANALÓGICO (MEDE A INTENSIDADE DO CAMPO MAGNÉTICO)
int pinoDigital = 8; //PINO DIGITAL (DETECTA A PRESENÇA DO CAMPO MAGNÉTICO)
int pinLedVd = 7; // define the LED pin
int pinLedVm = 6; // define the LED pin

  
void setup (){
  pinMode(pinoAnalogico, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode(pinoDigital, INPUT); //DEFINE O PINO COMO ENTRADA
  Serial.begin(9600); //INICIALIZA A SERIAL
  lcd.begin (16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
  lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)
  pinMode(pinLedVd, OUTPUT);
  pinMode(pinLedVm, OUTPUT);
}

void loop (){

  Serial.print("APROXIME-SE"); //IMPRIME O TEXTO NO MONITOR SERIAL
  
  lcd.setCursor(0,0); //SETA A POSIÇÃO DO CURSOR
  lcd.print("APROXIME-SE");
  
  if(digitalRead(pinoDigital) == HIGH){ //SE LEITURA DO PINO FOR IGUAL A HIGH, FAZ
      Serial.println("Detectado"); //IMPRIME O TEXTO NO MONITOR SERIAL
      lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
      lcd.print("DETECTADO              ");
      digitalWrite(pinLedVd, HIGH);
      digitalWrite(pinLedVm, LOW);
      
  }else{ //SENÃO
      Serial.println("Não detectado"); //IMPRIME O TEXTO NO MONITOR SERIAL
      lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
      lcd.print("NAO DETECTADO     ");
      digitalWrite(pinLedVd, LOW);
      digitalWrite(pinLedVm, HIGH);
  }
  Serial.println("----------------------------------------------------------------"); //IMPRIME O TEXTO NO MONITOR SERIAL
  delay(500); //INTERVALO DE 500 MILISSEGUNDOS
}
