#include <stdio.h>
#include <stdlib.h>
int contador(char *p);
void insertar(char cad[200]);
int evaluar(int i, int j, char *p1, char *p2);
void restar(int *p, int i, int j,int *p1, int *p2);
void imprimir(int m,int *p);
void transformar(int i, char *p1, int *c, char *r);
void main()
{
int *p;
int i,j,m,mayor;
char cad1[200],cad2[200];
printf("Ingrese el primer número (debe tener entre 40 y 70 cifras):\n");
insertar(cad1);
i=contador(cad1);
printf("Ingrese el segundo número (debe tener entre 40 y 70 cifras):\n");
insertar(cad2);
j=contador(cad2);
mayor=(i>j)?i:j;
p=malloc(sizeof(int)*mayor);
m=evaluar(i,j,cad1,cad2);
int cat1[i],cat2[j];
char ref[10]={'0','1','2','3','4','5','6','7','8','9'};
transformar(i,cad1,cat1,ref);
transformar(j,cad2,cat2,ref);
if(m==0)
	{
	restar(p,i,j,cat1,cat2);
	}
else
	{
	restar(p,j,i,cat2,cat1);
	}
imprimir(mayor,p);
free(p);
}

void transformar(int i, char *p1, int *c,char *r)
{
int j,k;
for(;*p1!='\0';p1++)
	{
	for(k=0;k<10;k++)
		{
		if(*p1==*(r+k))
			{
			*c=k;
			c++;
			}	
		}
	}
}

void imprimir(int m,int *p)
{
int i;
printf("La resta es:\n");
if(*p!=0)
{
for(i=0;i<m;i++)
	printf("%d",*(p+i));
}
else
{
for(i=1;i<m;i++)
printf("%d",*(p+i));
}
printf("\n");
}

void restar(int *p, int i, int j,int *p1, int *p2)
{
int k,l,d;
for(i=i-1,j=j-1;j>=0;i--,j--)
	{
	k=*(p1+i)-*(p2+j);
	d=i-1;
	l=k;
	while(l<0)
		{
		*(p1+d)=*(p1+d)-1;
		l=*(p1+d);
		if(*(p1+d)<0)
			{
			*(p1+d)=*(p1+d)+10;
			}
		d--;
		}
	if(k<0)
		{
		k=10+k;
		}
	*(p+i)=k;
	}
if(i>=0)
	{
	for(;i>=0;i--)
	*(p+i)=*(p1+i);
	}
}

int evaluar(int i, int j, char *p1, char *p2)
{
int b=0,m,c,d;
if(i>j)
return 0;
else if (i<j)
return 1;
else
	{
	for(m=0;b==0&&m<i;m++,p1++,p2++)
		{
		c=*(int*)p1;
		d=*(int*)p2;
		if (c<d)
		b=1;
		}
	if(b==0)
		return 0;
	else
		return 1;
	}
}

void insertar(char cad[200])
{
int i=0;
while(i<40||i>70)
	{
	gets(cad);
	i=contador(cad);
	if(i<40||i>70)
	printf("Ingrese nuevamente el valor\n");
	}
}

int contador(char *p)
{
int i;
for(i=0;*(p+i)!='\0';i++);
return i;
}
