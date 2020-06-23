#include <stdlib.h>
#include <stdio.h>

#define length 10

void replace_char(char *ch, char c1, char c2)
{
	int i;
	for(i=0; *(ch+i)!='\0';i++)
		if(*(ch+i)==c1) *(ch+i) = c2;
}

int main()
{
	char mychar[length];
	char c1, c2;
	printf("Enter a string without space: \n");
	scanf("%10s\n",mychar);
	
	replace_char(mychar, 'h', 't');
	printf("Show the string: %s\n",mychar);
	return 1;
}