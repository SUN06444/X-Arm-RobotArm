#include <Arduino.h>
#include <WMHead.h> //WeMake主程式
#include <WMBoard.h> //WeMake主程式

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;

WMUltrasonic Ultrasonic_3(3); //UItrasonoc_3為超音波傳感器接口3
WMServo wmServo_2(2); //機器手臂運行接口2

void setup(){
    randomSeed(A0); //WeMake主程式
    delay(1000);
}

void loop(){
    if((Ultrasonic_3.Distance()) < (20)){ //當超音波感測距離 < 20
        wmServo_2.runActionGroup(1,1);  //機器手臂執行1號動作組1次
        while(!(wmServo_2.getRunOverCmd())); //直到機器手臂執行動作完畢
    }  
}

