#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 3

int main() 
{
	
	int array[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,3},{4,5,6},{7,8,9}};
	int* ptr;
	
	for(ptr=array; ptr <= &array[ARRAY_SIZE-1][ARRAY_SIZE-1]; ptr++)
	{
		printf(" %d", *ptr);
	}
	return 0;
}