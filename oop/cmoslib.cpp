class cmoslib
{
public:
	
	char getValue(char adr){
		char r;
		asm("mov al, byte ptr [ebp+8]");
		asm("out 0x70, al");
		asm("in al, 0x71");
		asm("mov byte ptr [ebp-4], al");
		return r;
	}

	int getDriveQuantity(){
		int res = this->getValue(0x14);
		if(res&1){
			res=(res>>6)+1;
		}else{
			res=0;
		}
		return res;
	}

	int getDisplayType(){
		return (this->getValue(0x14)>>4)&3;
	}

	int bcdDecode(char val)
	{
		return ((val & 0xF0) >> 4) * 10 + (val & 0xF);
	}
};