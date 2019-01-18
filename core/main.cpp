#include "lib/window.cpp"
#include "lib/stdio.cpp"
//#include "program/pong.cpp"
#include "system/disc.cpp"
#include "program/imgView.cpp"
#include "program/logoMish.cpp"
#include "lib/drawBMP.cpp"
#include "program/clock.cpp"
#include "program/paint.cpp"

int _start(){
	hdd disk = hdd();
	disk.readData(0x80000,2,0x18);

	Logo logo = Logo();
	
	while(logo.update());

	//Clock clock = Clock();
	Paint prog = Paint();
	out io = out();
	window win = window();
	//imgView prog = imgView();
	while(1){
		prog.update();
		if (win.FPSLimiter(60)){
			//clock.update();
			//prog.update();
			
			if(win.exit()){
				break;
			}
		}
	}

	while(logo.updateExit()){};
	
	while(1);
}