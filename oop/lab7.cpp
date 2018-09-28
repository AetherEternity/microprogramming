#include "video.cpp"
#include "keyboard.cpp"
#include "cmoslib.cpp"

int _start(){
	video screen=video();
	keyboard keys=keyboard();
	cmoslib cmos=cmoslib();
	int color=0x00ff00, multiplier=4;
	char driveMSG[18]="Drive quantity=0\n";
	char displayMSG0[]="None, EGA\n";
	char displayMSG1[]="CGA, EGA, VGA 40x25\n";
	char displayMSG2[]="CGA, EGA, VGA 80x25\n";
	char displayMSG3[]="Monochrome\n";
	switch(cmos.getDriveQuantity()){
		case 1: 
		{
			driveMSG[15]='1';
			break;
		}
		case 2: 
		{
			driveMSG[15]='2';
			break;
		}
		case 3: 
		{
			driveMSG[15]='3';
			break;
		}
		case 4: 
		{
			driveMSG[15]='4';
			break;
		}
	}
	screen.drawString(driveMSG,0,50,color,multiplier,5);
	switch(cmos.getDisplayType()){
		case 0: 
		{
			screen.drawString(displayMSG0,0,100,color,multiplier,5);
			break;
		}
		case 1: 
		{
			screen.drawString(displayMSG1,0,100,color,multiplier,5);
			break;
		}
		case 2: 
		{
			screen.drawString(displayMSG2,0,100,color,multiplier,5);
			break;
		}
		case 3: 
		{
			screen.drawString(displayMSG3,0,100,color,multiplier,5);
			break;
		}
	}
	while(1){}
}