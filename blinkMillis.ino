const int Led4=13;

int LedState4 = LOW;
int StateLed4cycle = 0;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup(){
  pinMode(led4,OUTPUT);
}


void loop(){
  blink4();
}

void blink4(){
		unsigned long currentMillis = millis();

		if (currentMillis - previousMillis >= interval) {
			previousMillis = currentMillis;

			if (ledState4 == LOW) { ledState4 = HIGH;} else { ledState4 = LOW;}
			digitalWrite(Led4, ledState4);
		}
	}
