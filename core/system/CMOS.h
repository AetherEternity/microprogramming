#ifndef CMOS_H
#define CMOS_H
unsigned char outb(unsigned char port,unsigned char arg);
unsigned char getCMOS(unsigned char data);
unsigned char getSeconds();
int bcdToNumber(unsigned char val);
void binify(char* str, unsigned char ch);

#endif