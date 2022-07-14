#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "list.h"

int main(int argc, char **argv)
{
	List_t List;
	float one=1.0f;
	float two=2.0f;
	float three=3.0f;
	float *ptr=NULL;

	// Initalize list, pre-allocate 10 items
	List_Init(&List, sizeof(float), 10, NULL);

	// Populate list
	List_Add(&List, &one);
	List_Add(&List, &two);
	List_Add(&List, &three);
	List_Add(&List, &one);
	List_Add(&List, &two);
	List_Add(&List, &three);
	List_Add(&List, &one);
	List_Add(&List, &two);
	List_Add(&List, &three);
	List_Add(&List, &one);

	for(int i=0;i<List_GetCount(&List);i++)
	{
		ptr=List_GetPointer(&List, i);
		printf("Index: %d, Data: %f\n", i, *ptr);
	}

	// Remove the second "three"
	List_Del(&List, 5);

	// Set the third float in the list to 123.321
	ptr=List_GetPointer(&List, 2);
	*ptr=123.321f;

	printf("\n");

	for(int i=0;i<List_GetCount(&List);i++)
	{
		float *ptr=NULL;

		ptr=List_GetPointer(&List, i);
		printf("Index: %d, Data: %f\n", i, *ptr);
	}

	List_Destroy(&List);

	return 0;
}