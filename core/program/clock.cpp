#include "../system/video.cpp"
#include "../lib/stdio.cpp"
#include "../system/CMOS.h"
//1024 * 768
class Clock{
public:

    Clock(){
        this->videoAddr=*(char**) (0x8000);
        screen.color = 0x000000;    
    }

    int update(){
        screen.color=0xffffff;
        screen.drawLine(214,108,814,108);
        screen.drawLine(814,108,814,708);
        screen.drawLine(814,708,214,708);
        screen.drawLine(214,708,214,108);
        screen.drawCircleFill(10,514,408);

        second = bcdToNumber(getSeconds());
        min = bcdToNumber(getCMOS(0x02));
        hr = bcdToNumber(getCMOS(0x04));

        if(second<8){
            screen.drawLine(512,408,512+41*second,108);
        }else
        if(second<23){
            screen.drawLine(512,408,814,118+41*(second-8));
        }else
        if(second<38){
            screen.drawLine(512,408,804-41*(second-23),708);
        }else
        if(second<53){
            screen.drawLine(512,408,214,698-41*(second-38));
        }else
        if(second<60){
            screen.drawLine(512,408,224+41*(second-53),108);
        }

        if(second<8){
            screen.drawLine(512,408,512+41*second,108);
        }else
        if(second<23){
            screen.drawLine(512,408,814,118+41*(second-8));
        }else
        if(second<38){
            screen.drawLine(512,408,804-41*(second-23),708);
        }else
        if(second<53){
            screen.drawLine(512,408,214,698-41*(second-38));
        }else
        if(second<60){
            screen.drawLine(512,408,224+41*(second-53),108);
        }

    }

private:
    int dotsX[150];

    int second,min,hr;

    char* videoAddr;
    out io = out();
    video screen = video();
    int t=0,darkerSpeed = 15;
    
    int random_seed = 0;

};