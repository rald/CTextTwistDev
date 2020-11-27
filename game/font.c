#include "font.h"

Font *Font_New(const int width,const int height,const int frames,const int *pixels) {
	Font *font=malloc(sizeof(Font));
	if(font) {
		font->width=width;
		font->height=height;
		font->frames=frames;
		font->pixels=pixels;		
	}
	return font;
}

void Font_Free(Font *font) {
	free(font);
	font=NULL;
}

void Font_DrawText(Font *font,int x,int y,char *text,int size,GLuint color) {
	int i,j,k;
	int xc=x,yc=y;
	for(k=0;k<strlen(text);k++) {
		for(j=0;j<font->height;j++) {
			for(i=0;i<font->width;i++) {
				
				int frame=text[k];
				int idx=i+j*font->width+frame*font->width*font->height;
				
				if(font->pixels[idx]==1) {
				
					int x0=i*size+xc;
					int y0=j*size+yc;
					int x1=x0+size;
					int y1=y0+size;
					
					glBoxFilled(x0,y0,x1,y1,color);
					
				}							
			}	
		}

		xc+=font->width*size;
		if(xc>=SCREEN_WIDTH) {
			xc=0;
			yc+=font->height*size;
		}	
			
	}
}
