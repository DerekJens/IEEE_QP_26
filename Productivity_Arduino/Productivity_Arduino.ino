


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

 

  
}
