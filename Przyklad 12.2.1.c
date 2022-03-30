#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 6   

int main()
{
	
	int array[ARRAY_SIZE] = {1,2,3,4,5,6};
	int *ptrArray;
	
	for(ptrArray = array; ptrArray-array < ARRAY_SIZE; ptrArray++)
	{
		printf("%d ", *ptrArray);
	}
	return 0;
}