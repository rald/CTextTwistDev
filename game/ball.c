#include "ball.h"

Ball *Ball_New(char letter,double x,double y) {
	Ball *ball=malloc(sizeof(Ball));
	if(ball) {
		ball->letter=toupper(letter);
		ball->x=x;
		ball->y=y;
		ball->dx=x;
		ball->dy=y;
	}
	return ball;
}

void Ball_Free(void *ball) {
	free(ball);
	ball=NULL;
}

void Ball_Draw(Ball *ball) {
	glSprite(ball->x,ball->y,GL2D_FLIP_NONE,&sprites[52]);
	glSprite(ball->x,ball->y,GL2D_FLIP_NONE,&sprites[ball->letter-'A']);		
}

void Ball_Update(Ball *ball) {
	
}
