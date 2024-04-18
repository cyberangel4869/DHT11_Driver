#include <Arduino.h>
#include <OLED_Font.h>
#include <OLED.h>
#include <DHT11_Driver.h>

#define led(x) digitalWrite(2,x) 
TEMP_HUMD temp_humid;

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  
  pinMode(2,OUTPUT);
  OLED_Init();
  OLED_Clear();
  OLED_ShowString(1,1,"Temperature:\0");
  OLED_ShowString(3,1,"Humidity:\0");
  pinMode(18,OUTPUT);
  digitalWrite(18,1);
  pinMode(21,OUTPUT);
  digitalWrite(21,0);
  
  int i;
  
}

void loop() {
  /*
  int x,y;
  for(y=0;y<8;y++)
  {
    OLED_SetCursor(y,0);
    for(x=0;x<128;x++)
  {
    if(x%8==0)
    {
      OLED_WriteData(0xff);
    }
    else{OLED_WriteData(0x01);}
  
  }
  }
  while(1);
  */
  led(1);
  /*
  temp_humid = read_temp_and_humd();
  OLED_ShowNum(2,2,temp_humid.temp_int,2);
  OLED_ShowChar(2,4,'.');
  OLED_ShowNum(2,5,temp_humid.temp_flt,1);
  OLED_ShowString(2,6," C\0");
  OLED_ShowNum(4,2,temp_humid.humd_int,2);
  OLED_ShowChar(4,4,'.');
  OLED_ShowNum(4,5,temp_humid.humd_flt,1);
  OLED_ShowString(4,6," %\0");
  led(0);
  delay(5000);*/
  // put your main code here, to run repeatedly:
}

// put function definitions here:
