#include "../system/video.cpp"
#include "../lib/stdio.cpp"
#include "../system/CMOS.h"
//1024 * 768
class Logo{
public:

    Logo(){
        this->videoAddr=*(char**) (0x8000);
        screen.color = 0x000000;
        int r=255,g=0,b=0;
        for (int i=0;i<768;i++){
            if(r>0 && b == 0){
                r-=1;
                g+=1;
            }
            if(g>0 && r == 0){
                g-=1;
                b+=1;
            }
            if(b>0 && g == 0){
                b-=1;
                r+=1;
            }
            dotsC[i] = (r<<16)+(g<<8)+b;
        }
    }

    int update(){
        screen.color = dotsC[curColor];
        if(curColor<768){
            curColor++;
        }else{
            curColor=0;
        }
        
        if(direction==0){
            screen.setPixel(curX,curY);
            if(curX<maxX){
                curX++;
            }else{
                maxX--;
                direction++;
            }
        }
        if(direction==1){
            screen.setPixel(curX,curY);
            if(curY<maxY){
                curY++;
            }else{
                maxY--;
                direction++;
            }
        }
        if(direction==2){
            screen.setPixel(curX,curY);
            if(curX>1024-maxX){
                curX--;
            }else{
                //maxX--;
                direction++;
            }
        }
        if(direction==3){
            screen.setPixel(curX,curY);
            if(curY>786-maxY){
                curY--;
            }else{
                //maxY--;
                direction=0;
            }
        }
        if(maxX<0){
            screen.color = 0;
            screen.drawSquare(0,0,1024,786);
            return 0;
        }
        /*
        if(t>40){
            io.column = 360;
            io.line = 400;
            io.fontSize(50);
            io.printChar('B');
        }
        if(t>50){
            io.printChar('r');
        }
        if(t>60){
            io.printChar('o');
        }
        if(t>70){
            io.printChar(' ');
            io.printChar('O');
        }
        if(t>80){
            io.printChar('S');
        }

        if(t>100){
            io.line = 480;
            io.column = 420;
            io.printChar('=');
        }
        if(t>100){
            io.line = 520;
            io.printChar('3');
        }

        if (t>150){
            screen.color = 0x000000;
            screen.drawSquare(0,0,1024,768);
            t=0;
            return 0;
        }*/
        //t++;

        for(int i=0;i<1000;i++){
            for(int j;j<100;j++){}
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
    int dotsC[768];
    int maxX=1024,maxY=768;
    int curX=0,curY=0;
    int curColor = 0;
    int direction = 0;
    //1024 * 768


    char* videoAddr;
    out io = out();
    video screen = video();
    int t=0;
};