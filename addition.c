#include <reg51.h>
#include "uart.h"
void add();
void main(){
while(1){
add();
}
}

void add(){
	unsigned char num1, num2;
	SerialInit();
	
	Printf("Enter First Number :");
	num1 = ReadBytePC();
	Printf("Enter Second Number :");
	num2 = ReadBytePC();
	
	Printf("Addition ===> ");
	SendByte2PC(num1 + num2);
	
	}

