#ifndef ARRAY_H
#define ARRAY_H

#include "common.h"

typedef struct Array Array;

struct Array {
	void **data;
	int length;
};

Array *Array_New();
void Array_Free(Array *array,void(*freeData)(void *data));
void Array_Append(Array *array,void *data);
Array *Array_Load(char *path);
void Array_Shuffle(Array *array);

#endif
