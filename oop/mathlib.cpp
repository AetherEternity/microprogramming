class mathlib
{
public:
	
	int  intplus(int a, int b){
		int r;
		asm("finit");
	    asm("fild dword ptr [ebp+8]");
	    asm("fiadd dword ptr [ebp+12]");
	    asm("fistp dword ptr [ebp-4]");
	    return r;
	}
	
	int  intminus(int a, int b){
		int r;
		asm("finit");
	    asm("fild dword ptr [ebp+8]");
	    asm("fisub dword ptr [ebp+12]");
	    asm("fistp dword ptr [ebp-4]");
	    return r;
	}
	
	int  intmul(int a, int b){
		int r;
		asm("finit");
	    asm("fild dword ptr [ebp+8]");
	    asm("fimul dword ptr [ebp+12]");
	    asm("fistp dword ptr [ebp-4]");
	    return r;
	}
	
	int  intremainder(int a, int b){
        int r;
        asm("finit");
        asm("fild dword ptr [ebp+12]");
        asm("fild dword ptr [ebp+8]");
        asm("fprem");
        asm("fistp dword ptr [ebp-4]");
        return r;
    }

	int  intdiv(int a, int b){
		int r;
		asm("finit");
	    asm("fild dword ptr [ebp+8]");
	    asm("fidiv dword ptr [ebp+12]");
	    asm("fistp dword ptr [ebp-4]");
	    return r;
	}

};