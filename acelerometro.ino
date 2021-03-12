//Este programa puede cumplir con 3 funciones:
//1. Muestra las componentes de la aceleración correspondiente a cada eje
//2. Muestra el ángulo de rotación de los ejes X y Y
//3. Muestra el ángulo entre el eje Z y la vertical a partir de las aceleraciones en X y Y.
#include <LiquidCrystal.h> //Incluimos la librería para controlar la LCD.
#include <math.h> //Incluimos esta librería para poder utilizar las funciones trigonométricas
int analogX=A0, analogY=A1, analogZ=A2; //Declaramos los pines analógicos de entradas con sus respectivas variables
float val1=0,val2=0,val3=0, incx=0, incy=0; // Estas variables auxiliares ayudarán a manejar los cálculos.
LiquidCrystal lcd(12,11,5,4,3,2); //Se inicializan los pins para la LCD.
void setup() {
    Serial.begin(9600);  // Se inicializa el monitor serial 
    lcd.begin(16,2);  //Configuramos el número de columnas y número de filas de la LCD.
}

void loop() {
  val1=analogRead(analogX);//Lectura del eje x
  delay(100);
  val2=analogRead(analogY);// Lectura del eje Y
  delay(100);
  val3=analogRead(analogZ);// Lectura del eje Z
  delay(100);
  
  //Componentes de la aceleración (fracciones de g)
  val1=val1*100;// Multiplicamos los valores por 100 para tener un mapeo más correcto
  val1=map(val1, 27400,41200, -9800, 9800 );//Asociamos los límites con la aceleración 1 g igual a 9.8 m*s^-2
  val1=val1/1000;// Dividimos los resultados para obtener la aceleración correcta.
  val2= val2*100;
  val2= map(val2, 27000,40600,9800,-9800);
  val2=val2/1000;
  val3= val3*100;
  val3= map(val3, 27200,40900,9800,-9800);
  val3=val3/1000;
  
  /*
  //Ángulo de rotación
  val1=map(val1,273,410,-90,90); // Asociamos los límites con los ángulos máximo y mínimo
  val2=map(val2,264,405,-90,90);
  */
  
  
  //Ángulo de inclinación
  incx= atan(val1/sqrt(pow(val2,2) + pow(val3,2)))*(180.0/3.14);//Con esta fórmula encontramos el ángulo de inclinación 
  incy= atan(val2/sqrt(pow(val1,2) + pow(val3,2)))*(180.0/3.14);// utilizando las aceleraciones 
  Serial.print(" (X,Z): ");// Ángulo de Z con respecto a la vertical 
  Serial.print(incx);
  Serial.print("\t");
  Serial.print(" (Y,Z): ");
  Serial.println(incy); 
  lcd.setCursor(0,0);// Impresión de los resultados en el LCD
  lcd.print("AnguloX-Z:"); 
  lcd.setCursor(11,0);//
  lcd.print(incx);
  lcd.setCursor(0,1);
  lcd.print("AnguloY-Z:" ); //
  lcd.setCursor(11,1);
  lcd.print(incy);
  
  /*
  // Para mostrar los resultados en el serial monitor
  Serial.print(" X: "); 
  Serial.print(val1);
  Serial.print("\t");
  Serial.print(" Y: ");
  Serial.print(val2);
  Serial.print("\t");
  Serial.print(" Z: ");
  Serial.println(val3);
  */
 


}
