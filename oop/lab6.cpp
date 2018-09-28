#include "video.cpp"
#include "keyboard.cpp"
#include "mathlib.cpp"

/*int strtoint(char* str, int length){
	char alph[11]="0123456789";
	int r=0;
	for (int i = length; i < length; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (str[i]==alph[j]){
				r+=1010(length-i-1)*j;
			}
		}
	}
	return r;
}
*/
int _start(){
	video screen=video();
	keyboard keys=keyboard();
	mathlib math=mathlib();
	int color=0x00ff00, multiplier=4;
	//char message[30];
	//keys.getstr(message,3);
	//int num=strtoint(message,3);
	int num=100;
	//char res[12];
	int cnt=0;
	int rem;
	while (num>0){
		num=math.intdiv(num,2);
		rem=math.intremainder(num,2);
		if(rem){
			screen.drawChar(0+(15*cnt),50,color,multiplier,'1');
			//res[cnt]='1';
		}else{
			screen.drawChar(0+(15*cnt),50,color,multiplier,'0');
			//res[cnt]='0';
		}
		cnt++;
		keys.confirm();
	}
	//res[cnt]='\n';
	//screen.drawString(res,0,50,color,multiplier,5);
	while(1){}
}