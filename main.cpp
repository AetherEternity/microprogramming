#include <FreeImagePlus.h>
#include <iostream>

using namespace std;

void changeColor(uint32_t *ptr1,uint32_t *ptr2){
	asm("movdqu (%1), %%xmm0\n"
	"movdqu (%2), %%xmm1\n"
	"pxor %%xmm1, %%xmm0\n"
	"movdqu %%xmm0, (%0)": "=r"(ptr1) : "r"(ptr1),"r"(ptr2) : "xmm0","xmm1");
}


int main(int argc, char *argv[]){
	fipImage img;
	RGBQUAD rgbQuad;
	uint32_t rgb[4],rgbGain[4];
	int gain =0xff;

	char fileName[256];
	if(argc!=3){
		cout << "Usage: lab3.elf inputFile outputFile" <<endl;
		exit(0);
	}
	img.load(argv[1]);
	std::cout <<"Processing: "<<argv[1]<<' '<< img.getWidth() << "x" << img.getHeight()<<","<<img.getBitsPerPixel()<<"bit" << std::endl;
    for (int i=0;i<4;i++){
    	rgbGain[i] = (gain <<16) +  (gain<<8) + gain;
    }
    
	for (int i=0;i<img.getHeight();i++){
		for(int j=0;j<img.getWidth();j++){
			for (int k=0;k<4;k++){
				img.getPixelColor(j,i,&rgbQuad);
				rgb[k] = (int(rgbQuad.rgbRed) <<16) +  (int(rgbQuad.rgbGreen)<<8) +int(rgbQuad.rgbBlue);
				j++;
			}
			changeColor(rgb,rgbGain);
			j-=5;
			for (int k=0;k<4;k++){
				rgbQuad.rgbRed = rgb[k]>>16;
				rgbQuad.rgbBlue = rgb[k]%256;
				rgbQuad.rgbGreen = (rgb[k]>>8)%256;
				img.setPixelColor(j,i,&rgbQuad);
				j++;
			}
		}
		
	}

	img.save(argv[2]);
    return 0;
}
