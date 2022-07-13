#ifndef __LIST_H__
#define __LIST_H__

typedef struct
{
    size_t Size;
	size_t bufSize;
	size_t Stride;
    uint8_t *Buffer;
} List_t;

bool List_Init(List_t *List, size_t Stride, size_t Count, void *Data);
bool List_Add(List_t *List, void *Data);
bool List_Del(List_t *List, size_t Index);
void List_GetPointer(List_t *List, size_t Index, void **Pointer);
void List_GetCopy(List_t *List, size_t Index, void *Data);
void List_Clear(List_t *List);
void List_Destroy(List_t *List);

#endif
