#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x3f,16,2);

const int button_OK = 14; //A0
const int button_EXIT = 15; //A1
const int button_UP = 16; //A2
const int button_DOWN = 17; //A3

int buttonState_OK = 0;
int buttonState_EXIT = 0;
int buttonState_UP = 0;
int buttonState_DOWN = 0;

int i=0, j=0, k=0;
String onoff_0, onoff_1, onoff_2, onoff_3, onoff_4, onoff_x;

const int Led0=0;
const int Led1=1;
const int Led2=2;
const int Led3=3;
const int Led4=4;

int StateLed0=0;
int StateLed1=0;
int StateLed2=0;
int StateLed3=0;
int StateLed4=0;
int ledState4=0;
int StateLed4cycle = 0;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
	lcd.init();
	lcd.setBacklight(HIGH);
	pinMode(button_OK, INPUT_PULLUP);
	pinMode(button_EXIT, INPUT_PULLUP);
	pinMode(button_UP, INPUT_PULLUP);
	pinMode(button_DOWN, INPUT_PULLUP);
	pinMode(Led0, OUTPUT); digitalWrite(Led0, LOW);
	pinMode(Led1, OUTPUT); digitalWrite(Led1, LOW);
	pinMode(Led2, OUTPUT); digitalWrite(Led2, LOW);
	pinMode(Led3, OUTPUT); digitalWrite(Led3, LOW);
	pinMode(Led4, OUTPUT); digitalWrite(Led4, LOW);
}

void blink4();

void loop(){
	StateLed0=digitalRead(Led0);
	StateLed1=digitalRead(Led1);
	StateLed2=digitalRead(Led2);
	StateLed3=digitalRead(Led3);
	StateLed4=digitalRead(Led4);
	lcd.setCursor(1,0);
	lcd.print("Led controller");
	lcd.setCursor(1,1);
	lcd.print("Prog");
	lcd.setCursor(6,1);
	lcd.print(StateLed0);
	lcd.setCursor(8,1);
	lcd.print(StateLed1);
	lcd.setCursor(10,1);
	lcd.print(StateLed2);
	lcd.setCursor(12,1);
	lcd.print(StateLed3);
	lcd.setCursor(14,1);
	lcd.print(StateLed4);

	buttonState_OK = digitalRead(button_OK);
	if(buttonState_OK == LOW){
		delay(300); i=1; lcd.clear();

		while(i > 0) {
			if(StateLed0==0){ onoff_0 = "OFF";}else{ onoff_0 = "ON";}
			if(StateLed1==0){ onoff_1 = "OFF";}else{ onoff_1 = "ON";}
			if(StateLed2==0){ onoff_2 = "OFF";}else{ onoff_2 = "ON";}
			if(StateLed3==0){ onoff_3 = "OFF";}else{ onoff_3 = "ON";}
			if(StateLed4cycle==0){ onoff_4 = "OFF";}else{ onoff_4 = "ON";}

			lcd.setCursor(6,0);
			lcd.print("Menu:");
			lcd.setCursor(0,1);
			lcd.print("Program");
			lcd.setCursor(9,1);
			lcd.print(j);
			lcd.setCursor(11,1);
			lcd.print(onoff_x);

			buttonState_OK = digitalRead(button_OK);
			if(buttonState_OK == LOW){ delay(300); k++; if(k>1){ k=0;} lcd.clear();}

			buttonState_EXIT = digitalRead(button_EXIT);
			if(buttonState_EXIT == LOW){ i=0; lcd.clear();}

			buttonState_UP = digitalRead(button_UP);
			if(buttonState_UP == LOW){ j--; delay(300); if(j<0){ j=4;} lcd.clear();}

			buttonState_DOWN = digitalRead(button_DOWN);
			if(buttonState_DOWN == LOW){ j++; delay(300); if(j>4){ j=0;} lcd.clear();}


			if(j==0){ onoff_x=onoff_0;
				while(k==1) { onoff_x=onoff_0;
					lcd.setCursor(6,0);
					lcd.print("Edit:");
					lcd.setCursor(1,1);
					lcd.print("Led Pin");
					lcd.setCursor(9,1);
					lcd.print(j);
					lcd.setCursor(11,1);
					lcd.print(onoff_x);

					if(StateLed0==0){ onoff_0 = "OFF";}else{ onoff_0 = "ON ";}

					buttonState_OK = digitalRead(button_OK);
					if(buttonState_OK == LOW){ k=0; delay(300); }

					buttonState_EXIT = digitalRead(button_EXIT);
					if(buttonState_EXIT == LOW){ k=0; delay(300);}

					buttonState_UP = digitalRead(button_UP);
					if(buttonState_UP == LOW){ delay(300); StateLed0++; if(StateLed0>1){ StateLed0=0;}}

					buttonState_DOWN = digitalRead(button_DOWN);
					if(buttonState_DOWN == LOW){ delay(300); StateLed0++; if(StateLed0>1){ StateLed0=0;}}

					digitalWrite(Led0, StateLed0);
					blink4();
				}
			}

			if(j==1){ onoff_x=onoff_1;
				while(k==1) { onoff_x=onoff_1;
					lcd.setCursor(6,0);
					lcd.print("Edit:");
					lcd.setCursor(1,1);
					lcd.print("Led Pin");
					lcd.setCursor(9,1);
					lcd.print(j);
					lcd.setCursor(11,1);
					lcd.print(onoff_x);

					if(StateLed1==0){ onoff_1 = "OFF";}else{ onoff_1 = "ON ";}

					buttonState_OK = digitalRead(button_OK);
					if(buttonState_OK == LOW){ k=0; delay(300); }

					buttonState_EXIT = digitalRead(button_EXIT);
					if(buttonState_EXIT == LOW){ k=0; delay(300);}

					buttonState_UP = digitalRead(button_UP);
					if(buttonState_UP == LOW){ delay(300); StateLed1++; if(StateLed1>1){ StateLed1=0;}}

					buttonState_DOWN = digitalRead(button_DOWN);
					if(buttonState_DOWN == LOW){ delay(300); StateLed1++; if(StateLed1>1){ StateLed1=0;}}

					digitalWrite(Led1, StateLed1);
					blink4();
				}
			}

			if(j==2){ onoff_x=onoff_2;
				while(k==1) { onoff_x=onoff_2;
					lcd.setCursor(6,0);
					lcd.print("Edit:");
					lcd.setCursor(1,1);
					lcd.print("Led Pin");
					lcd.setCursor(9,1);
					lcd.print(j);
					lcd.setCursor(11,1);
					lcd.print(onoff_x);

					if(StateLed2==0){ onoff_2 = "OFF";}else{ onoff_2 = "ON ";}

					buttonState_OK = digitalRead(button_OK);
					if(buttonState_OK == LOW){ k=0; delay(300); }

					buttonState_EXIT = digitalRead(button_EXIT);
					if(buttonState_EXIT == LOW){ k=0; delay(300);}

					buttonState_UP = digitalRead(button_UP);
					if(buttonState_UP == LOW){ delay(300); StateLed2++; if(StateLed2>1){ StateLed2=0;}}

					buttonState_DOWN = digitalRead(button_DOWN);
					if(buttonState_DOWN == LOW){ delay(300); StateLed2++; if(StateLed2>1){ StateLed2=0;}}

					digitalWrite(Led2, StateLed2);
					blink4();
				}
			}

			if(j==3){ onoff_x=onoff_3;
				while(k==1) { onoff_x=onoff_3;
					lcd.setCursor(6,0);
					lcd.print("Edit:");
					lcd.setCursor(1,1);
					lcd.print("Led Pin");
					lcd.setCursor(9,1);
					lcd.print(j);
					lcd.setCursor(11,1);
					lcd.print(onoff_x);

					if(StateLed3==0){ onoff_3 = "OFF";}else{ onoff_3 = "ON ";}

					buttonState_OK = digitalRead(button_OK);
					if(buttonState_OK == LOW){ k=0; delay(300); }

					buttonState_EXIT = digitalRead(button_EXIT);
					if(buttonState_EXIT == LOW){ k=0; delay(300); }

					buttonState_UP = digitalRead(button_UP);
					if(buttonState_UP == LOW){ delay(300); StateLed3++; if(StateLed3>1){ StateLed3=0;}}

					buttonState_DOWN = digitalRead(button_DOWN);
					if(buttonState_DOWN == LOW){ delay(300); StateLed3++; if(StateLed3>1){ StateLed3=0;}}

					digitalWrite(Led3, StateLed3);
					blink4();
				}
			}

			if(j==4){ onoff_x=onoff_4;
				while(k==1) { onoff_x=onoff_4;
					lcd.setCursor(6,0);
					lcd.print("Edit:");
					lcd.setCursor(0,1);
					lcd.print("Blink Pin");
					lcd.setCursor(10,1);
					lcd.print(j);
					lcd.setCursor(12,1);
					lcd.print(onoff_x);

					if(StateLed4==0){ onoff_4 = "OFF";}else{ onoff_4 = "ON ";}

					buttonState_OK = digitalRead(button_OK);
					if(buttonState_OK == LOW){ k=0; delay(300); lcd.clear();}

					buttonState_EXIT = digitalRead(button_EXIT);
					if(buttonState_EXIT == LOW){ k=0; delay(300); lcd.clear();}

					buttonState_UP = digitalRead(button_UP);
					if(buttonState_UP == LOW){ delay(300); StateLed4++; StateLed4cycle++;
						if(StateLed4>1){ StateLed4=0;}if(StateLed4cycle>1){ StateLed4cycle=0;}}

					buttonState_DOWN = digitalRead(button_DOWN);
					if(buttonState_DOWN == LOW){ delay(300); StateLed4++; StateLed4cycle++;
						if(StateLed4>1){ StateLed4=0;}if(StateLed4cycle>1){ StateLed4cycle=0;}}
						blink4();
				}
			}
		blink4();
		}
	blink4();
	}
blink4();
}


void blink4(){
	if (StateLed4cycle == 1){
		unsigned long currentMillis = millis();

		if (currentMillis - previousMillis >= interval) {
			previousMillis = currentMillis;

			if (ledState4 == LOW) { ledState4 = HIGH;} else { ledState4 = LOW;}
			digitalWrite(Led4, ledState4);
		}
	}else{ digitalWrite(Led4, LOW);}
}
