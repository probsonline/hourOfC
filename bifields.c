#include <stdio.h>

/* Note: this will give 8 bytes as size on a 32-bit machine as structure will be padded after char for 3 bytes
 and 4 bytes for int will be used, where actually data will be only in 16 bits. If we want to start every bit 
 field on the next int boundry define a variable like int pad:0 i.e. specify bitfield size 0 to align. That means
 bitfields are not really for space saving but more for making sure that only enough data can fit in and flows otherwise
 As can also be seen that bitfields are not portable due to endianess dependency.
 Moreover for the same reason, a poitner to a bitfield cannot be made
 bitfields can't be static and arrays for bitfields can't be declared
 Bits more than the size of the data type can't be specified i.e. int x:34 is invalid */
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

	//Notes

}


