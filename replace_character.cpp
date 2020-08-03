#include <stdlib.h>
#include <stdio.h>

#define length 10


void replace_char(char *charRoot, char char1, char char2) {
	for (int i = 0; *(charRoot + i) != '\0'; i++) {
		if (*(charRoot + i) == char1)
			*(charRoot + i) == char2;
	}
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