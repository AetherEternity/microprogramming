#include "secondlab_SecondLab.h"
#include <stdint.h>

void pxor(uint32_t *ptr1, uint32_t *ptr2)
{
	asm("movdqu (%1), %%xmm0\n"
		"movdqu (%2), %%xmm1\n"
		"pxor %%xmm1, %%xmm0\n"
		"movdqu %%xmm0, (%0)": "=r"(ptr1) : "r"(ptr1),"r"(ptr2) : "xmm0","xmm1");
}

JNIEXPORT void JNICALL Java_secondlab_SecondLab_process (JNIEnv *e , jclass class, jintArray arr)
{
	
	jint* array = (*e)->GetIntArrayElements(e, arr, JNI_FALSE);
	
	printf("size of int is %ld\n", sizeof(jint));
	printf("Processing image\n");
	for(int i = 0; (*e)->GetArrayLength(e, arr) - i >= 4; i += 4)
	{
		static uint32_t mask[4] = {0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff};
		pxor(array + i, mask);
	}
	printf("\n");
	(*e)->ReleaseIntArrayElements(e, arr, array, 0);
	return;
}
