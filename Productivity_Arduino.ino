
const int collectSwitch = 5;

int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600)
  pinMode(collectSwitch, INPUT);

}


void loop() {
  // put your main code here, to run repeatedly:
  int lightValue = analogRead(A0); //light sensor
  int tempValue = analogRead(A1); //temp sensor
  int soundValue = analogRead(A2); //sound sensor
  switchState = digitalRead(collectSwitch);

  int averageLight{0};
  int averageTemp{0};
  int averageSound{0};

  if(switchState == HIGH){
    int count = 0;

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

     if(count == 5){
       break;
     }
  }
}
