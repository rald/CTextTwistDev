#include "array.h"

Array *Array_New() {
	Array *array=malloc(sizeof(Array));
	if(array) {
		array->data=NULL;
		array->length=0;
	}
	return array;
}

void Array_Free(Array *array,void(*freeData)(void *data)) {

	int i;
	
	for(i=0;i<array->length;i++) {
		freeData(array->data[i]);
		array->data[i]=NULL;
	}

	free(array->data);
	array->data=NULL;
	free(array);
	array=NULL;
}

void Array_Append(Array *array,void *data) {
	array->data=realloc(array->data,sizeof(void*)*(array->length+1));
	array->data[array->length++]=data;
}

Array *Array_Load(char *path) {
	Array *array=NULL;
	char line[STRING_MAX];
	FILE *fin=fopen(path,"r");

	if(!fin) {
		return NULL;
	}

	array=Array_New();
	
	while(fgets(line,STRING_MAX-1,fin)) {
		char *p=strchr(line,'\n'); if(p) *p='\0';
		Array_Append(array,strdup(line));
	}

	return array;
}

void Array_Shuffle(Array *array) {
	int i,j;
	for(i=array->length-1;i>0;i--) {
		j=rand()%(i+1);
		void *tmp=array->data[i];
		array->data[i]=array->data[j];
		array->data[j]=tmp;
	}
}
