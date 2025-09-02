#include<stdio.h>
main(){
    int Mt,x,y,a,b,res;
    printf("Entrer un montant en dollar:\n");
    scanf("%d",&Mt);
    
    x= Mt/20;
    res=Mt-(x*20);
    y=res/10;
    res=res-(y*10);
    a=res/5;
    res=res-(a*5);
    b=res/1;
    res=res-(b*1);
    printf("Billet de 20$=%d\n",x);
    printf("Billet de 10$=%d\n",y);
    printf("Billet de 5$=%d\n",a);
    printf("Billet de 1$=%d\n",b);

    return 0;
}