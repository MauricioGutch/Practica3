//Este programa permite conocer la temperatura con el sensor DS18B20
//Para obtener la temperatura del sensor LM35, es necesario amplificar la señal. Se ha realizado la prueba exitosamente en Proteus.
#include <LiquidCrystal.h> //Incluimos la librería para controlar la LCD.
/*
#include <OneWire.h> //Se incluye esta librería que permite la comunicación con un solo pin
#include <DallasTemperature.h>//Se incluye la librería Dallas para realizar la lectura del sensor
#define one_Wire 9 //Se configura el pin 9 como entrada
OneWire oneWire(one_Wire);//Creamos un objeto OneWire para comunicarnos con el sensor.
//Pasamos nuestra resferencia oneWire a la instancia de DallasTemperature
DallasTemperature sensorT(&oneWire);//Se crea un objeto DallasTemperature que leera el OneWire
*/
LiquidCrystal lcd(12,11,5,4,3,2); //Se inicializan los pins para la LCD.


 // Estas líneas son para leer la señal analógica amplificada del LM-35 
int analogPin= A0;
float val=0;

void setup() {
   Serial.begin(9600); // inicializamos el monitor serial a 9600 baudios
    lcd.begin(16,2);  //Configuramos el número de columnas y número de filas de la LCD.
  //sensorT.begin();//Inicializamos la librería
  pinMode(analogPin, INPUT); //Inicializamos el pin A0 como entrada analógica
}
void loop() {
  /*
  sensorT.requestTemperatures(); //Se pide al sensor la temperatura
  Serial.print("Temperatura: ");
  Serial.print(sensorT.getTempCByIndex(0));//Obtiene la temperatura del sensor
  Serial.println(" °C");
  delay(200);
*/

  //Con estas líneas obtenemos la señal amplificada del LM-35
  val= analogRead(analogPin);
  val= (val*5)/1023;
  val= val*10;
  //Mostramos la temperatura en el LCD
  lcd.print("Temperatura:");
  lcd.setCursor(3,1);
  lcd.print(val); 
  lcd.setCursor(10,1);
  lcd.print("C");
  delay(100);

/*
  lcd.setCursor(1,0);//
  lcd.print("Temperatura:");
  lcd.setCursor(3,1);
  //Aquí adquirimos la temperatura del puerto serial 0 donde está configurado el sensor.
  lcd.print(sensorT.getTempCByIndex(0)); 
  lcd.setCursor(10,1);
  lcd.print("C");
  */
  }
