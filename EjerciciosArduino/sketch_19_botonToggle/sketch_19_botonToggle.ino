int buzz = 8;
int buttonPin = 7;
int buttonRead;

int newButton = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buzz, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {
  while (buttonRead == 0){
    digitalWrite(buzz, LOW);
  
    buttonRead = digitalRead(buttonPin);
    Serial.println(buttonRead);
    delay(100);
  }
  while (buttonRead == 1){
    digitalWrite(buzz, LOW);
  
    buttonRead = digitalRead(buttonPin);
    Serial.println(buttonRead);
    delay(100);

    if (buttonRead == 0){
      newButton = 1;
    }
  }
  
  while (newButton == 1){
    while(buttonRead == 0){
      digitalWrite(buzz, HIGH);
      buttonRead = digitalRead(buttonPin);
      Serial.println(buttonRead);
      delay(100);   
    }
    while(buttonRead == 1){
      digitalWrite(buzz, HIGH);
      buttonRead = digitalRead(buttonPin);
      if (buttonRead == 0){
          newButton = 0;
        }
      }
      Serial.println(buttonRead);
      delay(100);  
    }
    
  }

