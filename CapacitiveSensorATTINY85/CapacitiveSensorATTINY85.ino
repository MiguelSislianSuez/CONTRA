#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */
 int led = 2;
CapacitiveSensor   cs_4_3 = CapacitiveSensor(4,3);        // 10M resistor between pins 4 & 3, pin 3 is sensor pin, add a wire and or foil if desired
/*CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil*/
 const long numReadings = 4; //numero de lecturas
 long readings[numReadings]; //arrray de las lecturas. Definiendo el tamaño del array 
 int readIndex = 0; //puntero al indice actual. Le digo el lugar del array que va a modificar
 long total = 0;
 long average = 0; //average para hacer la media
 

void setup() 
                   
{
  
   cs_4_3.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   pinMode (2, OUTPUT);
   for (int thisReading = 0; thisReading < numReadings; thisReading++){
    readings[thisReading] = 0; //aquí inicializamos el array a 0. Reset
   
    
   }

}

void loop(){
  
    long actual =  cs_4_3.capacitiveSensor(30);

    total = total-readings[readIndex]; //restamos la ultima lectura
    readings[readIndex]=actual; //metemos en la posición de array actual el valor que obtenemos 
    total = total + readings[readIndex]; //añade el valor actual al total
    readIndex = readIndex + 1; // marca la siguiente posición del array
    if (readIndex >= numReadings) readIndex = 0; //si ha llegado al final del array vuelve al principio
    average = total / numReadings; //calcula la media

 if (actual > average *2) { //valor mayor que la media se multiplica 
      digitalWrite (led, HIGH);
}else if (actual < average / 2){
            digitalWrite (led, LOW);
}
           

    /*
   
    if (actual > 1000) 
      digitalWrite (led, HIGH);
      if (actual < 30)
            digitalWrite (led, LOW);


            

    /*} else {
      digitalWrite (led, LOW);
    }
    
    /*long total2 =  cs_4_6.capacitiveSensor(30);
    long total3 =  cs_4_8.capacitiveSensor(30);*/

    /*Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing

    Serial.print(actual);                  // print sensor output 1
    Serial.print("\t");
    /*Serial.print(total2);                  // print sensor output 2
    Serial.print("\t");
    Serial.println(total3);               // print sensor output 3*/

    delay(10);                             // arbitrary delay to limit data to serial port 
}
