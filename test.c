#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "list.h"

int main(int argc, char **argv)
{
	List_t list;
	float one=1.0f;
	float two=2.0f;
	float three=3.0f;
	float *ptr=NULL;

	// Initalize list, pre-allocate 10 items
	List_Init(&list, sizeof(float), 10, NULL);

	// Populate list
	List_Add(&list, &one);
	List_Add(&list, &two);
	List_Add(&list, &three);
	List_Add(&list, &one);
	List_Add(&list, &two);
	List_Add(&list, &three);
	List_Add(&list, &one);
	List_Add(&list, &two);
	List_Add(&list, &three);
	List_Add(&list, &one);

	for(int i=0;i<List_GetCount(&list);i++)
	{
		ptr=List_GetPointer(&list, i);
		printf("Index: %d, Data: %f\n", i, *ptr);
	}

	// Remove the second "three"
	List_Del(&list, 5);

	// Set the third float in the list to 123.321
	ptr=List_GetPointer(&list, 2);
	*ptr=123.321f;

	printf("\n");

	for(int i=0;i<List_GetCount(&list);i++)
	{
		float *ptr=List_GetPointer(&list, i);
		printf("Index: %d, Data: %f\n", i, *ptr);
	}

	printf("\nList size: %lld bytes\nActual buffer size: %lld bytes\n", list.size, list.bufSize);

	List_ShrinkFit(&list);

	printf("\nAfter shrink fit:\nList size: %lld bytes\nActual buffer size: %lld bytes\n", list.size, list.bufSize);

	for(int i=0;i<List_GetCount(&list);i++)
	{
		ptr=List_GetPointer(&list, i);
		printf("Index: %d, Data: %f\n", i, *ptr);
	}

	List_Destroy(&list);

	return 0;
}