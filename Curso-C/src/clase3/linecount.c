#include <stdio.h>

int main(){

	int c, lc;
	lc = 0 ;

	while((c = getchar()) != EOF)
		if (c == '\n')
			++lc;

	printf("Number of lines is %d \n",lc);
	return 0;
}