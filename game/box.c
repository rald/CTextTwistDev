#include "box.h"

Box *Box_New(int x,int y) {
	Box *box=malloc(sizeof(Box));
	if(box) {
		box->x=x;
		box->y=y;
	}
	return box;
}

void Box_Free(void *box) {
	free(box);
}

void Box_Draw(Box *box) {
	glSprite(box->x,box->y,GL2D_FLIP_NONE,&sprites[53]);
}

