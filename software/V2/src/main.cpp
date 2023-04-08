#include <Arduino.h>
#include <Adafruit_NeoPixel.h>


#define WS2812_PIN          27           //定义选择引脚
#define WS2812_NUM          1            //定义led个数，决定数组长度

Adafruit_NeoPixel strip = Adafruit_NeoPixel(WS2812_NUM, WS2812_PIN, NEO_GRB + NEO_KHZ800);

void colorWipe(uint32_t color, int wait);
void theaterChase(uint32_t color, int wait);
void rainbow(int wait);
void theaterChaseRainbow(int wait);



//驱动ic的四引脚
int icPin[]={16,17,18,19};//A,B,C,D
byte num1=0,num2=0;
int count=0;

//初始化
void init(){
  Serial.begin(115200);
  randomSeed(A0);//A0作为变量，提供真-随机数
  pinMode(icPin[0],OUTPUT);  //A
  pinMode(icPin[1],OUTPUT);  //B
  pinMode(icPin[2],OUTPUT);  //C
  pinMode(icPin[3],OUTPUT);  //D

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)把对应pin设置为输出
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)，设置亮度
  
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
  case 10:
    digitalWrite(icPin[0],HIGH);
    digitalWrite(icPin[1],HIGH);
    digitalWrite(icPin[2],HIGH);
    digitalWrite(icPin[3],HIGH);
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
  // int aaa=0;
  // for(aaa=0;aaa<10;aaa++){
  //   Tube_ShowNum(aaa);
  //   delay(1000);
  //   Serial.println(aaa);
  // }
    // Tube_ShowNum(4);

    Tube_ShowNum(count);
    count++;

  
  // colorWipe(strip.Color(255,   0,   0), 50); // Red
  // colorWipe(strip.Color(  0, 255,   0), 50); // Green
  // colorWipe(strip.Color(  0,   0, 255), 50); // Blue

  // // Do a theater marquee effect in various colors...
  // theaterChase(strip.Color(127, 127, 127), 50); // White, half brightness
  // theaterChase(strip.Color(127,   0,   0), 50); // Red, half brightness
  // theaterChase(strip.Color(  0,   0, 127), 50); // Blue, half brightness

  rainbow(10);             // Flowing rainbow cycle along the whole strip
  theaterChaseRainbow(10); // Rainbow-enhanced theaterChase variant

  // delay(50);
  if(count==10){count=0;}
    // Tube_ShowNum(10);
// // io12触摸，按一下加一个数字
// if(touch_pad_press_12()){
//     Tube_ShowNum(num1);
//     num1++;
//     num1=num1%10;
//     // Serial.println(num1);
//     delay(500);
// }

// //io14触摸，按住快速显示随机数
// if(touch_pad_press_14()){
//     num2=random(10);
//     Tube_ShowNum(num2);
//     // Serial.println(num2);
//     delay(100);
//   }

}

// Some functions of our own for creating animated effects -----------------

// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

// Theater-marquee-style chasing lights. Pass in a color (32-bit value,
// a la strip.Color(r,g,b) as mentioned above), and a delay time (in ms)
// between frames.
void theaterChase(uint32_t color, int wait) {
  for(int a=0; a<10; a++) {  // Repeat 10 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in steps of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show(); // Update strip with new contents
      delay(wait);  // Pause for a moment
    }
  }
}

// Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
void rainbow(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this loop:
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    // strip.rainbow() can take a single argument (first pixel hue) or
    // optionally a few extras: number of rainbow repetitions (default 1),
    // saturation and value (brightness) (both 0-255, similar to the
    // ColorHSV() function, default 255), and a true/false flag for whether
    // to apply gamma correction to provide 'truer' colors (default true).
    strip.rainbow(firstPixelHue);
    // Above line is equivalent to:
    // strip.rainbow(firstPixelHue, 1, 255, 255, true);
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}

// Rainbow-enhanced theater marquee. Pass delay time (in ms) between frames.
void theaterChaseRainbow(int wait) {
  int firstPixelHue = 0;     // First pixel starts at red (hue 0)
  for(int a=0; a<30; a++) {  // Repeat 30 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in increments of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        // hue of pixel 'c' is offset by an amount to make one full
        // revolution of the color wheel (range 65536) along the length
        // of the strip (strip.numPixels() steps):
        int      hue   = firstPixelHue + c * 65536L / strip.numPixels();
        uint32_t color = strip.gamma32(strip.ColorHSV(hue)); // hue -> RGB
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show();                // Update strip with new contents
      delay(wait); // Pause for a moment
      firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
    }
  }
}
