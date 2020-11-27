#ifndef BALL_H
#define BALL_H

#include "common.h"

typedef struct Ball Ball;

struct Ball {
	char letter;
	double x,y;
	double dx,dy;
	double speed;
};

Ball *Ball_New(char letter,double x,double y);
void Ball_Free(void *ball);
void Ball_Draw(Ball *ball);
void Ball_Update(Ball *ball);

#endif

