#include <stdio.h>

void mmxAdd(char* a1,char* a2){
	asm("mov rbx, [rbp-16]");
	asm("movq mm0, qword ptr [rbx]");
	asm("mov rbx, [rbp-8]");
	asm("movq mm1, qword ptr [rbx]");
	asm("paddb mm0, mm1");
	asm("movq qword ptr [rbx], mm0");
}

int main(void)
{
	char arr1[8]={1,2,3,4,5,6,7,8};
	char arr2[8]={9,10,11,12,13,14,15,16};
	mmxAdd(arr1, arr2);
	printf("%d %d %d %d %d %d %d %d\n", arr1[0],arr1[1],arr1[2],arr1[3],arr1[4],arr1[5],arr1[6],arr1[7]);
	return 0;
}