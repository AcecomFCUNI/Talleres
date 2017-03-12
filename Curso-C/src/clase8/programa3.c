#include <stdio.h>
#define FIL 10
#define COL 12
void llenar(int** array){
	int i,j;
	for (i = 0; i < FIL; ++i){
		for (j = 0; j < COL; ++j){
		 	*(*(array+i)+j)=i*j;
		 	printf("%d \n",*(*(array+i)+j) );
		}
	}	
}
void main(){
	int A[FIL][COL];
	llenar(A);

	

}