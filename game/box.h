#ifndef BOX_H
#define BOX_H

#include "common.h"

typedef struct Box Box;

struct Box {
	int x,y;
};

Box *Box_New(int x,int y);
void Box_Free(void *box);
void Box_Draw(Box *box);

#endif