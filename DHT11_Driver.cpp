#include <Arduino.h>
#include <DHT11_Driver.h>


bool sensor_is_connect()//check weather the sensor is connected.
{
  int t=0;
  pinMode(DATA,OUTPUT_OPEN_DRAIN);
  digitalWrite(DATA,0);
  delay(20);
  pinMode(DATA,INPUT);
  while (digitalRead(DATA)==1)//wait for ask.
  {
    delay(1);
    t++;
    if(t>1000){return false;}
  }
  if(digitalRead(DATA)==0)//sensor ask.
  {return true;}
}

void link_start()//send commend so that the sensor start to work.
{
  pinMode(DATA,OUTPUT_OPEN_DRAIN);
  digitalWrite(DATA,0);
  delay(20);
  pinMode(DATA,INPUT);
  while (digitalRead(DATA)==1);//wait for ask.
  while(digitalRead(DATA)==0);//sensor ask.
}

int read_data(void)//read 8 bits datas once a time.
{
  int data=0,n;
  pinMode(DATA,INPUT);
  while(digitalRead(DATA)==1);//ready to send datas.
  for(n=8;n>0;n--)
  {
    while(digitalRead(DATA)==0);//every time data level jump from low to high,one bit will be send.
    data=data<<1;
    if(digitalRead(DATA)==1)//read data.
    {
      ets_delay_us(30);
      if(digitalRead(DATA)==1)//if the high level last 70us,it means 1.
      {
        data+=1;
        while(digitalRead(DATA)==1);//wait next bit.
        continue;
      }
      else//if the high level last 26-28us,it means 0.
      {
        data+=0;
        continue;
      }
    }
  }
  return data;
}

TEMP_HUMD read_temp_and_humd(void)//return the tempurature( 'C) and the humidity( %).
{
  TEMP_HUMD temp_humid;
  link_start();
  temp_humid.humd_int=read_data();
  temp_humid.humd_flt=read_data();
  temp_humid.temp_int=read_data();
  temp_humid.temp_flt=read_data();
  return temp_humid;
}
