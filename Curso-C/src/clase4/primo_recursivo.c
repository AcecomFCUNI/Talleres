#include <stdio.h>
int primo(int n,int x,int cont){
   if(x> n/2||cont>1){
   	    if(cont!=1|| n==1) 
          return 0;
	      else 
          return 1;
    }
   else{
        if(n%x==0) cont+=1;
	         return primo(n,x+1,cont);
   }
}

void main(){
  for(int i=1;i<=30;i++){
	if(primo(i,1,0)==1) printf("\t %d es primo\n",i);
	else printf("\t %d no es primo\n",i);
  }

}