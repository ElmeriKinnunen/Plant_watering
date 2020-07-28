int sensor_pin0 = A0;
int sensor_pin1 = A1; 
int sensor_pin2 = A2; 
int sensor_pin3 = A3;  
int output_value ;
int pump0 = 9;
int pump1 = 10;
int pump2 = 11;
int pump3 = 12;


#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 5
#define DHTTYPE    DHT11     // DHT 11
DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup() {
  Serial.begin(9600);
  dht.begin();
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  delayMS = sensor.min_delay / 500;
  
  Serial.println("\n Note, This is just a prototype!");
  delay(2000);
  Serial.println("Reading From the Sensors ... \n");
  delay(3000);
  Serial.println("Enter number 7 to get to the MENU");
  
  pinMode(pump0, OUTPUT);
  pinMode(pump1, OUTPUT);
  pinMode(pump2, OUTPUT);
  pinMode(pump3, OUTPUT);
}

    char input = 0 ;

void loop() {

    digitalWrite(pump0, HIGH);
    digitalWrite(pump1, HIGH);
    digitalWrite(pump2, HIGH);
    digitalWrite(pump3, HIGH);

    if (Serial.available() > 0) {
      input = Serial.read();
  
    switch (input){
      
      case '1':

        do {

        delay(delayMS);
        
        // Get temperature.
        sensors_event_t event;
        dht.temperature().getEvent(&event);
        if (isnan(event.temperature)) {
          Serial.println(F("Error reading temperature!"));
        }
        else {
          Serial.print(F("Air Temperature: "));
          Serial.print(event.temperature);
          Serial.println(F("°C"));
        }
        
        // Get humidity.
        dht.humidity().getEvent(&event);
        if (isnan(event.relative_humidity)) {
          Serial.println(F("Error reading humidity!"));
        }
        else {
          Serial.print(F("Air Humidity: "));
          Serial.print(event.relative_humidity);
          Serial.println(F("%"));
        }
      
        output_value = analogRead(sensor_pin0);
        output_value = map(output_value,623,364,0,100);
        Serial.print("Moisture of flower : ");
        Serial.print(output_value);
        Serial.println("%");
          if (output_value < 10){
            digitalWrite(pump0, LOW);
            delay(10000);
            digitalWrite(pump0, HIGH);
          }else{
            digitalWrite(pump0, HIGH);
          }
            output_value = analogRead(sensor_pin1);
            output_value = map(output_value,610,351,0,100);
            Serial.print("Moisture of tomato : ");
            Serial.print(output_value);
            Serial.println("%");  
                if (output_value < 10){
                  digitalWrite(pump1, LOW);
                  delay(10000);
                  digitalWrite(pump1, HIGH);
                }else{
                  digitalWrite(pump1, HIGH);
                }
            
                output_value= analogRead(sensor_pin2);
                output_value = map(output_value,613,362,0,100);
                Serial.print("Moisture of palm : ");
                Serial.print(output_value);
                Serial.println("%");
                    if (output_value < 10){
                      digitalWrite(pump2, LOW);
                      delay(10000);
                      digitalWrite(pump2, HIGH);
                    }else{
                      digitalWrite(pump2, HIGH);
                    }
                
                      output_value= analogRead(sensor_pin3);
                      output_value = map(output_value,616,358,0,100);
                      Serial.print("Moisture of avocado : ");
                      Serial.print(output_value);
                      Serial.println("% \n");
                          if (output_value < 10){
                            digitalWrite(pump3, LOW);
                            delay(10000);
                            digitalWrite(pump3, HIGH);
                          }else{
                            digitalWrite(pump3, HIGH);
                          }

          Serial.println("Enter 0 to exit");
                    delay(3000);
          input = Serial.read();

                          
        } while (input != '0');
        Serial.println("Enter number 7 to get to the MENU");
        break;
        
        case '2':
          Serial.println("pump 0 is ON");
            digitalWrite(pump0, LOW);
            delay(10000);
            digitalWrite(pump0, HIGH);
          Serial.println("pump 0 is OFF");
          break;

        case '3':
           Serial.println("pump 1 is ON");
            digitalWrite(pump1, LOW);
            delay(10000);
            digitalWrite(pump1, HIGH);
          Serial.println("pump 1 is OFF");
          break;

        case '4':
           Serial.println("pump 2 is ON");
            digitalWrite(pump2, LOW);
            delay(10000);
            digitalWrite(pump2, HIGH);
          Serial.println("pump 2 is OFF");
          break;

        case '5':
          Serial.println("pump 3 is ON");
            digitalWrite(pump3, LOW);
            delay(10000);
            digitalWrite(pump3, HIGH);
          Serial.println("pump 3 is OFF");
          break;

        case '6':

        delay(delayMS);
        
        // Get temperature.
        sensors_event_t event;
        dht.temperature().getEvent(&event);
        if (isnan(event.temperature)) {
          Serial.println(F("Error reading temperature!"));
        }
        else {
          Serial.print(F("Air Temperature: "));
          Serial.print(event.temperature);
          Serial.println(F("°C"));
        }
        
        // Get humidity.
        dht.humidity().getEvent(&event);
        if (isnan(event.relative_humidity)) {
          Serial.println(F("Error reading humidity!"));
        }
        else {
          Serial.print(F("Air Humidity: "));
          Serial.print(event.relative_humidity);
          Serial.println(F("%"));
        }
      
        output_value = analogRead(sensor_pin0);
        output_value = map(output_value,623,364,0,100);
        Serial.print("Moisture 0 : ");
        Serial.print(output_value);
        Serial.println("%");
          
            output_value = analogRead(sensor_pin1);
            output_value = map(output_value,610,351,0,100);
            Serial.print("Moisture 1 : ");
            Serial.print(output_value);
            Serial.println("%");                  
            
                output_value= analogRead(sensor_pin2);
                output_value = map(output_value,613,362,0,100);
                Serial.print("Moisture 2 : ");
                Serial.print(output_value);
                Serial.println("%");
                    
                      output_value= analogRead(sensor_pin3);
                      output_value = map(output_value,616,358,0,100);
                      Serial.print("Moisture 3 : ");
                      Serial.print(output_value);
                      Serial.println("% \n");

                      Serial.println("Enter number 7 to get to the MENU");
        
        break;
    
        case '7':
            Serial.println("------- MENU -------");
            Serial.println("1. AUTO");
            Serial.println("2. MANUAL pump0");
            Serial.println("3. MANUAL pump1");
            Serial.println("4. MANUAL pump2");
            Serial.println("5. MANUAL pump3");
            Serial.println("6. INFO");
            Serial.println("7. MENU");
            Serial.println("--------------------");
            break;
            
    } // switch ends
  } // if ends
} // loop ends
