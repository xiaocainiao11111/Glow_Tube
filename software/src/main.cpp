#include <Arduino.h>

//驱动ic的四引脚
int icPin[]={16,17,18,19};
byte num1=0,num2=0;

//初始化
void init(){
  Serial.begin(115200);
  randomSeed(A0);//A0作为变量，提供真-随机数
  pinMode(icPin[0],OUTPUT);  //A
  pinMode(icPin[1],OUTPUT);  //B
  pinMode(icPin[2],OUTPUT);  //C
  pinMode(icPin[3],OUTPUT);  //D
}

//辉光管显示函数
void Tube_ShowNum(byte num){
  switch (num)
  {
  case 0:
    digitalWrite(icPin[0],LOW);
    digitalWrite(icPin[1],LOW);
    digitalWrite(icPin[2],LOW);
    digitalWrite(icPin[3],LOW);
    break;
  case 1:
    digitalWrite(icPin[0],HIGH);
    digitalWrite(icPin[1],HIGH);
    digitalWrite(icPin[2],LOW);
    digitalWrite(icPin[3],LOW);
    break;
  case 2:
    digitalWrite(icPin[0],HIGH);
    digitalWrite(icPin[1],HIGH);
    digitalWrite(icPin[2],HIGH);
    digitalWrite(icPin[3],LOW);
    break;
  case 3:
    digitalWrite(icPin[0],LOW);
    digitalWrite(icPin[1],HIGH);
    digitalWrite(icPin[2],HIGH);
    digitalWrite(icPin[3],LOW);
    break;
  case 4:
    digitalWrite(icPin[0],LOW);
    digitalWrite(icPin[1],LOW);
    digitalWrite(icPin[2],HIGH);
    digitalWrite(icPin[3],LOW);
    break;
  case 5:
    digitalWrite(icPin[0],HIGH);
    digitalWrite(icPin[1],LOW);
    digitalWrite(icPin[2],HIGH);
    digitalWrite(icPin[3],LOW);
    break;
  case 6:
    digitalWrite(icPin[0],HIGH);
    digitalWrite(icPin[1],LOW);
    digitalWrite(icPin[2],LOW);
    digitalWrite(icPin[3],LOW);
    break;
  case 7:
    digitalWrite(icPin[0],HIGH);
    digitalWrite(icPin[1],LOW);
    digitalWrite(icPin[2],LOW);
    digitalWrite(icPin[3],HIGH);
    break;
  case 8:
    digitalWrite(icPin[0],LOW);
    digitalWrite(icPin[1],LOW);
    digitalWrite(icPin[2],LOW);
    digitalWrite(icPin[3],HIGH);
    break;
  case 9:
    digitalWrite(icPin[0],LOW);
    digitalWrite(icPin[1],HIGH);
    digitalWrite(icPin[2],LOW);
    digitalWrite(icPin[3],LOW);
    break;
  default:
    break;
  }
}

//触摸消抖，大概10ms
static bool touch_pad_press_12()
{
    static int press_cnt1 = 0;
    bool ret_cnt1 = false;
    if(touchRead(12) < 15){
        press_cnt1 ++;
        if (press_cnt1 > 4) {
            if( touchRead(12) < 15){
                ret_cnt1 = true;
                press_cnt1 = -8;
            }
        }
    }else{
        press_cnt1 = 0;
    }    
    return ret_cnt1;
}

static bool touch_pad_press_14()
{
    static int press_cnt2 = 0;
    bool ret_cnt2 = false;
    if(touchRead(14) < 15){
        press_cnt2 ++;
        if (press_cnt2 > 4) {
            if( touchRead(14) < 15){
                ret_cnt2 = true;
                press_cnt2 = -8;
            }
        }
    }else{
        press_cnt2 = 0;
    }    
    return ret_cnt2;
}


void setup() {

  init();

}



void loop() {

//io12触摸，按一下加一个数字
if(touch_pad_press_12()){
    Tube_ShowNum(num1);
    num1++;
    num1=num1%10;
    // Serial.println(num1);
    delay(500);
}

//io14触摸，按住快速显示随机数
if(touch_pad_press_14()){
    num2=random(10);
    Tube_ShowNum(num2);
    // Serial.println(num2);
    delay(100);
  }

}

