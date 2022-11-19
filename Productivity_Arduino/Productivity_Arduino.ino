


  #include <dht.h>

  #define DHTPIN A2
  #define dht_apin A2
  

  dht DHT;

  int chk;
  float temp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 

}


void loop() {
  // put your main code here, to run repeatedly:
  int lightValue = analogRead(A1); //light sensor
  DHT.read11(dht_apin);
  temp = DHT.temperature;
  int soundValue = analogRead(A3); //sound sensor

//celcius to farenheit
  temp = (temp*9/5)+32;
    Serial.print("lightValue: ");
    Serial.println(lightValue);
    if(lightValue < 500){
      Serial.print("too dark");
    }
    else if(lightValue < 800){
      Serial.print("perfect");
    }
    else{
      Serial.print("too bright");
    }
    Serial.print(" ");
    Serial.print("TempValue: ");
    Serial.println(temp);
    Serial.print(" ");
    Serial.print("SoundValue: ");
    Serial.println(soundValue);
    delay(100);

 

<<<<<<< HEAD
  
=======
    for(int i = 0; i < 10; i++){
      averageLight = averageLight + analogRead(A0);
      averageTemp = averageTemp + analogRead(A1);
      averageSound = averageSound + analogRead(A2);
      delay(100);
     }

     averageLight = averageLight/10;
     averageTemp = averageTemp/10;
     averageSound = averageSound/10;
     
     Serial.print("Light: " averageLight "\n");
     Serial.print("Temp: " averageTemp "\n");
     Serial.print("Sound: " averageSound "\n");

     count++;

     if(count == 6){
       continue;
     }
  }
>>>>>>> af6d52fc6b7e7d38a8a82b5aa903eed0098ad083
}
