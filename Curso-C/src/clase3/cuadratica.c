    #include <stdio.h> 
    
    int main (){
    
        int a, b, c, d;
            
        printf("Ingrese a, b y c");
        scanf("%d %d %d",&a,&b,&c);
        
        d = b*b - 4*a*c;
        
        if (d > 0)
            printf("Tiene raices reales distintas \n");
        else if (d < 0 )
            printf("Tiene raices complejas\n");
        else 
            printf("Tiene solucion real unica\n");
        
        return 0;
    }