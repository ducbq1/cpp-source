#include <stdio.h>
#include <string.h>

enum {SUCCESS, FAIL, MAX_LEN = 81 };

void LineReadWrite(FILE *fin, FILE *fout)
{
	char buff[MAX_LEN];//xau de luu tru
	int r,len;
	r = fscanf(fin,"%s\n",buff);
	while (r!=EOF) {
		len = strlen(buff);	
		printf("%d %s", len, buff);
		fprintf(fout,"%d %s", len, buff);
		r = fscanf(fin,"%s\n",buff);
	}
}

int main(void) {
	FILE *fptr1, *fptr2;
	char filename1[]= "lab3w.txt";
	char filename2[]= "lab3.txt";
	int reval = SUCCESS;
	if ((fptr1 = fopen(filename1, "w")) == NULL){
		printf("Cannot open %s.\n", filename1);
		reval = FAIL;
	} else if ((fptr2 = fopen(filename2, "r")) == NULL){
		printf("Cannot open %s.\n", filename2);
		reval = FAIL;
	} else {
		LineReadWrite(fptr2, fptr1);
		fclose(fptr1);
		fclose(fptr2);	
	}
	return reval;
}

