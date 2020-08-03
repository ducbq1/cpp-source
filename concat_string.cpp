#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *concat2string(char *s1, char *s2)
{
	int n = strlen(s1);
	int m = strlen(s2);	
	char *p = (char*)malloc((n+m)*sizeof(char));
	int i;
	for(i=0;i<(n+m);i++)
	{
		if(i<n)
		   p[i] = s1[i];
		else
		   p[i] = s2[i-n];
	}	
	return p;
}

int main(void) {
	char *p;
	p = concat2string("hello_","world!");
	printf("%s\n",p);
	return 1;
}

