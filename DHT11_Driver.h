#include <Arduino.h>
#define DATA 19//设置数据引脚

struct TEMP_HUMD
{
  int temp_int;//温度值整数部分
  int temp_flt;//温度值小数部分
  int humd_int;//湿度百分比整数部分
  int humd_flt;//湿度百分比小数部分
};

bool sensor_is_connect();
void link_start();
int read_data(void);
TEMP_HUMD read_temp_and_humd(void);
