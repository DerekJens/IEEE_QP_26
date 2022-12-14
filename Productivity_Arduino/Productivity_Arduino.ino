

  #include <SoftwareSerial.h>
  #include <dht.h>

  #define DHTPIN A2
  #define dht_apin A2
  #define RxD 2
  #define TxD 3
  
  SoftwareSerial mySerial(RxD, TxD);


  dht DHT;

  int chk;
  float temp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);


}


void loop() {
  // put your main code here, to run repeatedly:

  float lightValue = analogRead(A1); //light sensor
  DHT.read11(dht_apin);
  temp = DHT.temperature;
  float soundValue = analogRead(A3); //sound sensor

  float averageLight = 0;
  float averageTemp = 0;
  float averageSound = 0;
//celcius to farenheit
  temp = (temp*9/5)+32;
  //printing values
  for(int count = 0; count < 10; count++){
    mySerial.print(" ");
    mySerial.print("lightValue: ");
    mySerial.println(lightValue);
    averageLight+=lightValue;
    delay(10);
    if(lightValue < 500){
      Serial.print(" too dark");
    }
    else if(lightValue < 800){
      Serial.print(" perfect");
    }
    else{
      Serial.print(" too bright");
    }
    mySerial.print(" ");
    mySerial.print("TempValue: ");
    mySerial.println(temp);
    averageTemp+=temp;
    delay(10);
    mySerial.print(" ");
    mySerial.print("SoundValue: ");
    mySerial.println(soundValue);
    averageSound+=soundValue;
    delay(100);
  }
  averageLight/=10;
  averageTemp/=10;
  averageSound/=10;
  mySerial.print("Light: ");
  if(averageLight < 300){
    mySerial.println("too dark");
  }
  else if(averageLight > 700){
    mySerial.println("too bright");
  }
  else{
    mySerial.println("perfect");
  }

  mySerial.print("Sound: ");
  if(averageSound > 50){
    mySerial.println("too loud");
  }
  else{
    mySerial.println("perfect");
  }

  mySerial.print("Temp: ");
  if(averageTemp < 65){
    mySerial.println("too cold");
  }
  else if(averageTemp > 80){
    mySerial.println("too warm");
  }
  else{
    mySerial.println("perfect");
  }
  
  while(1){}
 


}
