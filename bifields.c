#include <stdio.h>

struct myStruct{
	int x:11;
	int y:5;
	char ch1;
};




int main(){

	struct myStruct aStruct;

	aStruct.x = 0x567;	//Any value larger than what can fit in 11 bit will give overflow 
	aStruct.y = 0x011;
	aStruct.ch1 = 'A';

	printf("%s %d\n", "Printing struct with size:", (int)sizeof(aStruct));
	printf("Value of int:11 variable in struct is: %x\n", aStruct.x);

	aStruct.x = 0xA67;	//Any value larger than what can fit in 11 bit will give overflow 
	printf("Setting value of int:11 to 0xF67 to show overflow: %x\n", aStruct.x);

}
