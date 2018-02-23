#include <stdio.h>

struct myStruct{
	int x;
	int *xptr;
	char ch1;
};


//Little Endian and Big Endian will have affect on union. On a big endian architecture
union myUnion{
	int  x;
	char ch1;
};


int main(){

	struct myStruct aStruct;

	aStruct.x = 0x01234567;
	aStruct.xptr = &aStruct.x;
	aStruct.ch1 = 'A';

	printf("%s %d\n", "Printing struct with size:", (int)sizeof(aStruct));
	printf("%x Value of int variable in struct is: \n", aStruct.x);
	printf("%x Value of pointer to the variable is \n", aStruct.xptr);
	printf("%x Dereferenced value from the poitner is \n", *aStruct.xptr);
	printf("Character from struct is %c\n", aStruct.ch1);
	printf("%s %d\n", "Printing struct with size:", (int)sizeof(aStruct));

	union myUnion aUnion;
	aUnion.x = 0x01234567;
	aUnion.ch1 = 'A';	//Assuming 32-bit architecture, depending upon endianess it will overwrite 0x67 or 0x01 with 'A'

	printf("%s %d\n", "Printing union with size", (int)sizeof(aUnion));
	printf("%x int from union\n", aUnion.x);
	printf("%c Character from union \n", aUnion.ch1);
	printf("%x int value of Character from union \n", aUnion.ch1);

	char *p = (char *)&aUnion.x;
	printf("value of one byte from int of union %c\n", p[0]);	//If it was a little endian architecture, p[0] will not return ch1

}
