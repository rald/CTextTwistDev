#ifndef BUTTON_H
#define BUTTON_H

#include "common.h"

typedef struct Button Button;
typedef enum ButtonState ButtonState;
typedef void(*ButtonOnClick)(Button *button);

enum ButtonState {
	BUTTON_STATE_UP=0,
	BUTTON_STATE_DOWN,
	BUTTON_STATE_MAX
};

struct Button {
	int x,y;
	int width,height;
	int baseframe;
	int frame;
	ButtonState state;
	ButtonOnClick onClick;
};

Button *Button_New(int baseframe,int x,int y,int width,int height,ButtonOnClick onClick);
void Button_Free(Button *button);
void Button_Draw(Button *button);
void Button_Update(Button *button);

#endif
