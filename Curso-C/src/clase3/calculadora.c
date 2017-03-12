    /*Calculadora simple*/

    #include <stdio.h> 
    
    int main (){
    
        float num1, num2 ; 
        char op;
        
        printf("Inserta el operador: "); 
        scanf("%c",&op);

        printf("Inserta dos numeros: ");
        scanf("%f%f",&num1,&num2);

        switch(op){

            case '+':
                printf("%f %c %f = %f\n",num1,op,num2,num1 + num2);
                break;
            case '-':
                printf("%f %c %f = %f\n",num1,op,num2,num1 - num2);
                break;
            case '*':
                printf("%f %c %f = %f\n",num1,op,num2,num1 * num2);
                break;
            case '/':
                if(num2 != 0 )
                    printf("%f %c %f = %f\n",num1,op,num2,num1 / num2);

                else 
                    printf("Error Division entre cero >:v");
                break;
            default:
                printf("Operador incorrecto \n");
        }

        return 0;
    }