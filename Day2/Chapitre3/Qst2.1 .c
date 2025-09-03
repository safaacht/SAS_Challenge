#include<stdio.h>

main(){

    int n,x,res,N;
    printf("Entrer un nbr:\n");
    scanf("%d",&n);

    x=n/10;
    res=n%10;
    N=(res*10)+x;

    printf("Le nbr inverse est:%d\n",N);

    return 0;


}