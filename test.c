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

	// Initalize list
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

	for(int i=0;i<10;i++)
	{
		float *ptr=NULL;

		List_GetPointer(&List, i, &ptr);
		printf("Index: %d, Data: %f\n", i, *ptr);
	}

	// Remove the second "three"
	List_Del(&List, 5);

	printf("\n");

	for(int i=0;i<10;i++)
	{
		float *ptr=NULL;

		List_GetPointer(&List, i, &ptr);
		printf("Index: %d, Data: %f\n", i, *ptr);
	}

	return 0;
}