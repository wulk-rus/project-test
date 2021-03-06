#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x3f,16,2);

const int button_OK = A0;   //A0
const int button_EXIT = A1; //A1
const int button_UP = A2;   //A2
const int button_DOWN = A3; //A3

int buttonState_OK = 0;
int buttonState_EXIT = 0;
int buttonState_UP = 0;
int buttonState_DOWN = 0;

int i=0, j=0, k=0;

void setup() {
  lcd.init();
  lcd.setBacklight(HIGH);
  pinMode(button_OK, INPUT_PULLUP);
  pinMode(button_EXIT, INPUT_PULLUP);
  pinMode(button_UP, INPUT_PULLUP);
  pinMode(button_DOWN, INPUT_PULLUP);
}

void loop() {
  lcd.setCursor(1,0);
  lcd.print("Led controller");

  buttonState_OK = digitalRead(button_OK);
  if(buttonState_OK == LOW){
    delay(300); i=1; lcd.clear();

    while(i > 0) {
      lcd.setCursor(6,0);
      lcd.print("Menu:");
      lcd.setCursor(0,1);
      lcd.print("Program");
      lcd.setCursor(9,1);
      lcd.print(j);

      buttonState_OK = digitalRead(button_OK);
      if(buttonState_OK == LOW){ delay(300); k++; if(k>1){ k=0;} lcd.clear();}

      buttonState_EXIT = digitalRead(button_EXIT);
      if(buttonState_EXIT == LOW){ i=0; lcd.clear();}

      buttonState_UP = digitalRead(button_UP);
      if(buttonState_UP == LOW){ j--; delay(300); if(j<0){ j=4;} lcd.clear();}

      buttonState_DOWN = digitalRead(button_DOWN);
      if(buttonState_DOWN == LOW){ j++; delay(300); if(j>2){ j=0;} lcd.clear();}

      if(j==0){
        while(k==1) {
          lcd.setCursor(6,0);
          lcd.print("Edit:");
          lcd.setCursor(1,1);
          lcd.print("Led Pin");
          lcd.setCursor(9,1);
          lcd.print(j);




          buttonState_OK = digitalRead(button_OK);
          if(buttonState_OK == LOW){ k=0; delay(300); }

          buttonState_EXIT = digitalRead(button_EXIT);
          if(buttonState_EXIT == LOW){ k=0; delay(300);}

          buttonState_UP = digitalRead(button_UP);
          if(buttonState_UP == LOW){ delay(300);}

          buttonState_DOWN = digitalRead(button_DOWN);
          if(buttonState_DOWN == LOW){ delay(300);}
        }
      }

    }
  }
}
