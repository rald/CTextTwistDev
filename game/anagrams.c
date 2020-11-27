#include <ctype.h>

#include "common.h"

#include "array.h"

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

Array *getAnagrams(char *w, Array *d) {
	int i;
	Array *anagrams=Array_New();
	for(i=0;i<d->length;i++) {
		if(isAnagram(w,d->data[i])) {
			Array_Append(anagrams,strdup(d->data[i]));
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

int main() {

	int i;

	srand(time(NULL));

	Array *wordlist=Array_Load("wordlist.txt");
	Array *wordrand=Array_Load("wordrand.txt");
	
	char *word=wordrand->data[rand()%wordrand->length];

	Array *anagrams=getAnagrams(word,wordlist);

	qsort(anagrams->data,anagrams->length,sizeof(char*),cmplen);

	for(i=0;i<anagrams->length;i++) {
		if(i!=0) printf(", ");
		printf("%s",(char*)anagrams->data[i]);
	}
	printf("\n");
	
	Array_Free(anagrams,freeDataString);
	Array_Free(wordrand,freeDataString);
	Array_Free(wordlist,freeDataString);
	
	return 0;
}
