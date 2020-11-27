#include "button.h"

static void Button_UpdateUp(Button *button);
static void Button_UpdateDown(Button *button);

Button *Button_New(int baseframe,int x,int y,int width,int height,ButtonOnClick onClick) {
	Button *button=malloc(sizeof(Button));
	if(button) {
		button->x=x;
		button->y=y;
		button->width=width;
		button->height=height;
		button->baseframe=baseframe;
		button->frame=0;
		button->state=BUTTON_STATE_UP;
		button->onClick=onClick;
	}
	return button;
}

void Button_Free(Button *button) {
	free(button);
}

void Button_Draw(Button *button) {
	glSprite(button->x,button->y,GL2D_FLIP_NONE,&sprites[button->baseframe+button->frame]);
}

void Button_Update(Button *button) {
	switch(button->state) {
		case BUTTON_STATE_UP:	Button_UpdateUp(button); break;
		case BUTTON_STATE_DOWN:	Button_UpdateDown(button); break;
		default: break;
	}
}

static void Button_UpdateUp(Button *button) {
	int x,y;
	glfwGetMousePos(&x,&y);

	if(glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT)==GLFW_PRESS) {
		if(		x>=button->x && x<=button->x+button->width &&
				y>=button->y && y<=button->y+button->height) {
			button->frame=1;
			button->state=BUTTON_STATE_DOWN;		
		}		
	}
}

static void Button_UpdateDown(Button *button) {
	if(glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT)==GLFW_RELEASE) {
		button->frame=0;
		button->state=BUTTON_STATE_UP;
		button->onClick(button);
	}
}
