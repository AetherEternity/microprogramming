#include "../system/video.cpp"
#include "../lib/stdio.cpp"
#include "../system/CMOS.h"
#include "../system/keyboard.cpp"

//1024 * 768
class Paint{
public:

    Paint(){
        this->videoAddr=*(char**) (0x8000);
        screen.color = 0x000000;    
    }

    int update(){
        screen.color=0xffffff;
        screen.drawLine(214,108,814,108);
        screen.drawLine(814,108,814,708);
        screen.drawLine(814,708,214,708);
        screen.drawLine(214,708,214,108);

        
        screen.color = colors[curColor];
        screen.drawSquare(50,150,100,200);
        screen.color = 0xaaaaaa;
        screen.drawSquare(40,150,50,200);
        screen.drawSquare(40,140,100,150);
        screen.drawSquare(100,140,110,200);
        screen.drawSquare(40,200,110,210);

        screen.color = colors[0];
        screen.drawSquare(50,250,100,300);
        screen.color = colors[1];
        screen.drawSquare(50,350,100,400);
        screen.color = colors[2];
        screen.drawSquare(50,450,100,500);
        screen.color = colors[3];
        screen.drawSquare(50,550,100,600);
        screen.color = colors[4];
        screen.drawSquare(50,650,100,700);
        screen.color = colors[5];
        screen.drawSquare(150,450,200,500);


        if(toDtaw){
            screen.color = colors[curColor];
            screen.drawSquare(curX-curSize,curY-curSize,curX+curSize,curY+curSize);
        }
        curKey = key.pull();

        if(curKey=='w'){//w
            drawUnderPointer();
            if(curY>108){
                curY--;
            }
            drawPointer(curX,curY);

        }
        if(curKey=='s'){//s
            drawUnderPointer();
            if(curY<708){
                curY++;
            }
            drawPointer(curX,curY);
        }
        if(curKey=='d'){//d
            drawUnderPointer();
            if(curX<814){
                curX++;
            }
            drawPointer(curX,curY);
        }
        if(curKey=='a'){//a
            drawUnderPointer();
            if(curX>214){
                curX--;
            }
            drawPointer(curX,curY);
        }

        if(curKey=='f'){
            if(curColor<6){
                curColor++;
            }else{
                curColor=0;
            }
        }

        if(curKey=='r'){
            if(curSize<20){
                curSize++;
            }
        }
        if(curKey=='e'){
            if(curSize>2){
                curSize--;
            }
        }

        if(curKey==' '){
            toDtaw = !toDtaw;
        }



    }

private:

    void drawPointer(int x,int y){
        screen.color = 0x666666;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                undoCursor[i+j*5] = getColor(x-2+i,y-2+j);
            }
        }
        screen.drawSquare(x-2,y-2,x+2,y+2);
    }

    void drawUnderPointer(){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                screen.color = undoCursor[i+j*5];
                screen.setPixel(curX-2+i,curY-2+j);
            }
        }
            
    }

    int getColor(int x,int y){
        char *p;
        int color;

		p=this->videoAddr;
		p+=((y*1024)+x)*3;
        color = *(int*) p;
        return color;
    }

    int colors[6] ={0xffffff,0xff0000,0x00ff00,0x000000,0x0000ff,0x126425};
    int curColor = 0;
    int curX = 512;
    int curY = 400;
    int curSize = 10;
    int undoCursor[25];
    char contr=0;
    char curKey = 0;

    int toDtaw =0;

    char* videoAddr;
    out io = out();
    video screen = video();
    keyboard key;

};