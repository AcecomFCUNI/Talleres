#include <stdio.h>
void f1(int n){
	int i;
	float s=0;
	for (i = 1; i <=n ; ++i)
	{
		s+=1/i;
	}
	printf("la suma es %f\n",s );
}
int main()
{
	f1(5);
	return 0;
}