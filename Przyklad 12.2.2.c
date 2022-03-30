#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 6   

int main()
{
	
	int array[ARRAY_SIZE] = {1,2,3,4,5,6};
	int *ptrArray = array;
	int i;
	for( i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d ", *(ptrArray+i));
	}
	return 0;
}