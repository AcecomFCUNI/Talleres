#include<stdio.h>
int main(){
  int n=10,i;
  int a[n];
  for(i=0;i<n;i++){
     a[i]=(i+1)*2;
     printf("%d\n",a[i]);	  
  }
  return 0;
}
