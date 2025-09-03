#include<stdio.h>

int main(){

    int n,x,res,N;
    do{
         printf("\n Entrer un nbr:\n");
    scanf("%d",&n);
    if(n>9 && n<100){
        x=n/10;
        res=n%10;
        N=(res*10)+x;
        printf("Le nbr inverse est:%d\n",N);
    }
    else
     printf("Erreur!\n");

    }while (n<=9 || n>=100);

    return 0;
}