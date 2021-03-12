//Este programa realiza la lectura del Joystick y entrega valores de -1 a 1 dependiendo del movimiento.
#include <math.h>//Incluimos la librería para realizar los cálculos con las funciones trigonométricas
int analogPin1=A0; //Declaramos como entrada analógica el VRX del Joystick
int analogPin2=A1; //Declaramos como entrada analógica el VRY del Joystick
float val1=0, val2=0;
void setup() {
   Serial.begin(9600); // setup serial
}

void loop() {
  val1 = analogRead(analogPin1); // lectura de X
  val1=val1*100;//Ampliamos la señal para obtener un mapeo correcto
  delay(25);
  //Escalamiento de los valores
  if(val1<50000 & val1>=0){// Los límites de sensibilidad 
    val1=map(val1,0,51000,-100,0);//Mapeo con rangos ampliados 
    
  }
  else{
    if(val1>60000 & val1<=102300){// Los límites de sensibilidad
    val1=map(val1,60000,102300,0,100);
    }
    else{
    val1=0;
    }
  }
 
  val2= analogRead(analogPin2);// lectura de Y
  val2=val2*100;// Ampliamos la señal para obtener un mapeo correcto
  delay(25);
  if(val2<50000 & val2>=0){
    val2=map(val2,0,50000,-100,0);
  }
  else{
    if(val2>60000 & val2<=102300){
    val2=map(val2,60000,102300,0,100);
    }
    else{
    val2=0;
    }
  }
 
//Regreso a valores en el rango de [-1;1]
  val1=val1/100;
  val2=val2/100;
/*
    //Crea las señales sin para visualizar mejor las senoidales en Serial Plotter 
    val1=10*sin(val1);
    val2=10*sin(val2);
*/
   // Impresión de los valores en Serial Monitor 
  Serial.print ("X: ");
  Serial.print(val1); 
  Serial.print(" Y: "); // debug value
  Serial.println (val2);

}
