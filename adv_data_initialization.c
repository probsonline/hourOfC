#include <stdio.h>

/* Let's see how the data can be assigned to array, structures. Not all of these work in ANSI C*/

struct myStruct{
	int x;
	int y;
};	



void print_array(int x[], int len);

int main(){

	struct myStruct aStruct;

	puts("===========STRUCTS====================");
	printf("%s\n", "This is how the struct looks like");
	printf("%s\n", "struct myStruct{");
	printf("%s\n", "	int x:11;");
	printf("%s\n", "	int y:5;");
	printf("%s\n", "};");
	printf("\n");

	puts("Simple way of assigning values, separate from declaration");
	puts("aStruct.x = 5;");
	puts("aStruct.y = 10;");
	aStruct.x = 5;
	aStruct.y = 10;
	printf("%s %d\n", "aStruct.x=", aStruct.x);
	printf("%s %d\n", "aStruct.y=", aStruct.y);

	puts("Declaration and assignments combined ");
	puts("struct myStruct bStruct={.x=11, .y=13};");
	struct myStruct bStruct={.x=11, .y=13};
	bStruct.y = 10;
	printf("%s %d\n", "bStruct.x=", bStruct.x);
	printf("%s %d\n", "bStruct.y=", bStruct.y);

	puts("bStruct={21, 31};");
	bStruct={21, 31};	//only in C++11?
	printf("%s %d\n", "bStruct.x=", bStruct.x);
	printf("%s %d\n", "bStruct.y=", bStruct.y);

	puts("bStruct={x:8, y:16};");
	bStruct={x:8, y:16};
	printf("%s %d\n", "bStruct.x=", bStruct.x);
	printf("%s %d\n", "bStruct.y=", bStruct.y);

	puts("===========ARRAYS====================");
	int array1[]={1,2,3, 4, 5, 6, 7, 8, 9};

	puts("array1 = {1,2,3, 4, 5, 6, 7, 8, 9};");
	print_array(array1, sizeof(array1)/sizeof(array1[0]));

//	int array2[]={1,2,3,4,[4] = 40, 5, 6, [7 ... 9]=1, 10, 11, [15]15}; This will work only in C++ 11

}


void print_array(int x[], int len)
{
	printf("%s", "{ ");
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", x[i]);
		if (i != len-1)
		{
			printf(", ");
		}
	}
	printf("%s\n", "}");

}