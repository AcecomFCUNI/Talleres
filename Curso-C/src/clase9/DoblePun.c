#include <stdio.h>
#include <stdlib.h>
void main()
{
int i=0,j=0,b=0,n,m,M,N,k=1,r=1,c;
printf("Ingrese el numero de filas y de columnas de la forma (a b):");
scanf("%d %d",&M,&N);
m=M;
n=N;
c=(n*m)+1;
int **p1;
p1=malloc(sizeof(int*)*M);
for(i=0;i<M;i++)
	{
	p1[i]=malloc(sizeof(int*)*N);
	}
i=0;
while(r==1)
{
for(;j<N;j++,k++)
	*(*(p1+i)+j)=k;
if(k==c)
	r=0;
else
	{
	for(j=j-1,i=i+1;i<M;i++,k++)
		*(*(p1+i)+j)=k;
	if(k==c)
	r=0;
	else
		{
		for(i=i-1,j=j-1;j>=b;j--,k++)
			*(*(p1+i)+j)=k;
		if(k==c)
		r=0;
		else
			{
			for(j=j+1,i=i-1;i>b;i--,k++)
				*(*(p1+i)+j)=k;
			if(k==c)
			r=0;
			}
		}
	M--;		
	N--;
	b++;
	i++;
	j++;
	}
}

for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
	{
	printf("%d\t",*(*(p1+i)+j));
	}
printf("\n");
}
for(i=0;i<m;i++)
free(p1[i]);
free(p1);
}
