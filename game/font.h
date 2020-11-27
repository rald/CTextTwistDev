#ifndef FONT_H
#define FONT_H

#include "common.h"

typedef struct Font Font;

struct Font {
	int width,height;
	int frames;
	const int *pixels;
};

Font *Font_New(const int width,const int height,const int frames,const int *pixels);
void Font_Free(Font *font);
void Font_DrawText(Font *font,int x,int y,char *text,int size,GLuint color);

#endif
