#include "common.h"

#include "array.h"
#include "box.h"
#include "ball.h"
#include "button.h"

#include "uvcoord_sprites.h"

glImage sprites[SPRITES_NUM_IMAGES];

int *freq(char *w) {
	int i;

	int *f=malloc(sizeof(int)*26);

	for(i=0;i<26;i++) f[i]=0;

	for(i=0;i<strlen(w);i++) {
		int ch=toupper(w[i]);
		if(ch>='A' && ch<='Z') {
			f[ch-'A']++;
		}
	}

	return f;
}

bool isZero(int *f) {
	int i;
	for(i=0;i<26;i++) {
		if(f[i]!=0) return false;
	}
	return true;
}

bool isAnagram(char *w0,char *w1) {
	bool retval=true;
	
	int i;

	int *f0=freq(w0);
	int *f1=freq(w1);

	if(isZero(f0) || isZero(f1)) {
	
		retval=false;

	} else {	
	
		for(i=0;i<26;i++) {
			if(f0[i]<f1[i]) {
				retval=false;
				break;
			}
		}

	}

	free(f0);
	free(f1);
	
	return retval;
}

char *strupr(char *s) {
	int i;
	for(i=0;i<strlen(s);i++) {
		s[i]=toupper(s[i]);
	}
	return s;
}

Array *getAnagrams(char *w,Array *d) {
	int i;
	Array *anagrams=Array_New();
	for(i=0;i<d->length;i++) {
		if(isAnagram(w,d->data[i])) {
			char *u=strdup(d->data[i]);
			strupr(u);
			Array_Append(anagrams,u);
		}
	}
	return anagrams;
}

void freeDataString(void *data) {
	free(data);
}

int cmplen(const void *a,const void *b) {
	char *l=*(char**)a;
	char *r=*(char**)b;
	return strlen(l)-strlen(r);
}

char *shuffle(char *w) {
	int i,j;
	for(i=strlen(w)-1;i>0;i--) {
		j=rand()%(i+1);
		char tmp=w[i];
		w[i]=w[j];
		w[j]=tmp;
	}
	return w;
}

void twistButtonOnClick(Button *button) {
}

void enterButtonOnClick(Button *button) {
}

void lastWordButtonOnClick(Button *button) {
}

void clearButtonOnClick(Button *button) {
}

int main(int argc, char **argv) {

	double timeStart=0;
	bool quit=false;
	
	int i,j;

	GLuint spritesTexture;
	
	srand(time(NULL));

	Array *wordlist=Array_Load("wordlist.txt");
	Array *wordrand=Array_Load("wordrand.txt");
	
	char *word=strdup(wordrand->data[rand()%wordrand->length]);

	strupr(word);
	
	char *shuffledWord=strdup(word);
	
	shuffle(shuffledWord);

	Array *anagrams=getAnagrams(word,wordlist);

	Array_Shuffle(anagrams);

	qsort(anagrams->data,anagrams->length,sizeof(char*),cmplen);

	glScreenInit(SCREEN_WIDTH,SCREEN_HEIGHT);
	glfwSetWindowTitle(GAME_TITLE);
	glfwSwapInterval(1);
	glBlendMode(GL2D_ALPHA);

	spritesTexture = glLoadSpriteSet(	"images/TextTwist.tga",
						sprites,
						SPRITES_BITMAP_WIDTH,
						SPRITES_BITMAP_HEIGHT,
						SPRITES_NUM_IMAGES,
						sprites_texcoords,
						GL_NEAREST
					);
					
						
			
	glClearScreen();

	glBoxFilled(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,GL2D_RGBA(0,0,128,255));


	int gap=4;

/*
	int x0=gap;
	int y0=gap;
	int x1=x0;
	int y1=y0;
	int x2=x0;
	for(j=0;j<anagrams->length;j++) {
		for(i=0;i<strlen(anagrams->data[j]);i++) {		
			glSprite(x1,y1,GL2D_FLIP_NONE,&tiles[72]);
			glSprite(x1,y1,GL2D_FLIP_NONE,&tiles[((char*)anagrams->data[j])[i]-'A'+26]);
			x1+=32+gap;
			if(x1>x2) x2=x1;
		}
		x1=x0;
		y1+=32+gap;
		if(y1>=(32+gap)*10) {
			x0=x2+32+gap;
			x1=x0;
			y1=y0;
		}
	}

*/
	
	Array *boxes=Array_New();
	for(i=0;i<strlen(shuffledWord);i++) {
		int x=i*(64+gap)+(SCREEN_WIDTH-strlen(shuffledWord)*(64+gap))/2;
		int y=SCREEN_HEIGHT-64*3-gap*2-32;
		Array_Append(boxes,Box_New(x,y));
	}
		
	Array *balls=Array_New();	
	for(i=0;i<strlen(shuffledWord);i++) {
		int x=i*(64+gap)+(SCREEN_WIDTH-strlen(shuffledWord)*(64+gap))/2;
		int y=SCREEN_HEIGHT-64*2-gap-32;
		Array_Append(balls,Ball_New(shuffledWord[i],x,y));
	}
	
	Button *twistButton=Button_New(55,gap+(128+32)*0+16,SCREEN_HEIGHT-64-gap,128,64,twistButtonOnClick);
	Button *enterButton=Button_New(57,gap+(128+32)*1+16,SCREEN_HEIGHT-64-gap,128,64,enterButtonOnClick);
	Button *lastWordButton=Button_New(59,gap+(128+32)*2+16,SCREEN_HEIGHT-64-gap,128,64,lastWordButtonOnClick);
	Button *clearButton=Button_New(61,gap+(128+32)*3+16,SCREEN_HEIGHT-64-gap,128,64,clearButtonOnClick);

	while(!quit) {

		for(i=0;i<boxes->length;i++) {
			Box_Draw(boxes->data[i]);
		}
	
		for(i=0;i<balls->length;i++) {
			Ball_Draw(balls->data[i]);
		}
		
		Button_Draw(twistButton);
		Button_Draw(enterButton);
		Button_Draw(lastWordButton);
		Button_Draw(clearButton);
		
		Button_Update(twistButton);
		Button_Update(enterButton);
		Button_Update(lastWordButton);
		Button_Update(clearButton);

		glfwSwapBuffers();

		timeStart = glfwGetTime();
		while(glfwGetTime()-timeStart < 1.0/60.0) {};

		quit = glfwGetKey(GLFW_KEY_ESC) | !glfwGetWindowParam(GLFW_OPENED);

	}

	glDeleteTextures(1,&spritesTexture);

	glfwTerminate();

	free(shuffledWord);
	free(word);
	
	Array_Free(boxes,Box_Free);
	Array_Free(balls,Ball_Free);
	Array_Free(anagrams,freeDataString);
	Array_Free(wordrand,freeDataString);
	Array_Free(wordlist,freeDataString);

	return 0;
}
