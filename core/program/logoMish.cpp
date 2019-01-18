#include "../system/video.cpp"
#include "../lib/stdio.cpp"
#include "../system/CMOS.h"
//1024 * 768
class Logo{
public:

    Logo(){
        this->videoAddr=*(char**) (0x8000);
        screen.color = 0x000000;

        for (int i=0;i<100;i++){
            CircleR[i]=maxrand(51257,50);
            CircleC[i]=maxrand(12312421,0xffffff);
            CircleX[i]=maxrand(25782,1024);
            CircleY[i]=maxrand(97421,768);
        }
        //1024 * 768
    }

    int update(){

        for (int i=0;i<100;i++){
            screen.color = CircleC[i];
            screen.drawCircle(CircleR[i],CircleX[i],CircleY[i]);
            CircleR[i]++;
        }
        t++;
        if(t>100){
            for(int i=0;i<10000;i++){
            for(int j=0;j<10000;j++){}
             }
            screen.color=0;
            screen.drawSquare(0,0,1024,768);
            return 0;
        } 

        for(int i=0;i<10000;i++){
            for(int j=0;j<100;j++){}
        }
        return 1;
    }

    int updateExit(){
        screen.color = 0x000000;
        screen.drawSquare(0,0,1024,768);
        io.line = 60;
        io.printString("Power can be turned off");
        //outb(0xf4, 0x00);
        return 0;
    }

private:
    int CircleR[100],CircleC[100],CircleX[100],CircleY[100];
    


    char* videoAddr;
    out io = out();
    video screen = video();
    int t=0;

    int random_seed = 0;
    int maxrand(int seed,int max){
        random_seed = random_seed + seed * 1103515245 + 12345;
        return (unsigned int)(random_seed/65536) %(max+1);
    }

};