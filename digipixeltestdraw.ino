#include <DigiPixel.h>
#include <avr/pgmspace.h>


// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

int buttonDelay=10;
int contador=50;
int pixelX=0;
int pixelY=0;
int pixelColor=1;
int pixelState=0;

void setup(){
 Serial.begin(9600);
}


void loop(){ 
  
  movePixel();
  digiPixel.saveButtonStates();
  digiPixel.drawScreen();
  conteo();
}

void conteo(){
  if (contador!=0){
    contador--;
  }
  else {
    digiPixel.setPixel(pixelX,pixelY,pixelColor);
    if (pixelColor!=0){
      pixelColor=0;
      contador=50;
    }
    else {
      pixelColor=pixelState;
      contador=50;
    }
  }
}

void movePixel(){
  if (buttonDelay != 0){
    buttonDelay--; 
  }
  else{
    if (digiPixel.buttonUpPressed == true & pixelY < 7){
      buttonDelay = 10;
      digiPixel.setPixel(pixelX,pixelY,pixelState);
      pixelY++;
      digiPixel.setPixel(pixelX,pixelY,pixelColor);
    }
    if (digiPixel.buttonDownPressed == true & pixelY > 0){
      buttonDelay = 10;
      digiPixel.setPixel(pixelX,pixelY,pixelState);
      pixelY--;
      digiPixel.setPixel(pixelX,pixelY,pixelColor);
    } 
    if (digiPixel.buttonLeftPressed == true & pixelX > 0){
      buttonDelay = 10;
      digiPixel.setPixel(pixelX,pixelY,pixelState);
      pixelX--;
      digiPixel.setPixel(pixelX,pixelY,pixelColor);
    }
    if (digiPixel.buttonRightPressed == true & pixelX < 7){
      buttonDelay = 10;
      digiPixel.setPixel(pixelX,pixelY,pixelState);
      pixelX++;
      digiPixel.setPixel(pixelX,pixelY,pixelColor);
    } 
    if (digiPixel.buttonAPressed == true){
      buttonDelay = 15;
      pixelState++;
      pixelColor=pixelState;
      
    }   
      
  }
}

  




