#include<stdio.h>

int main(){
    int m1,j1,a1;
    int m2,j2,a2;

    printf("Entre la premiere date:\n");
    scanf("%d / %d / %d",&m1,&j1,&a1);
    printf("Entre la deuxieme date:\n");
    scanf("%d / %d / %d",&m2,&j2,&a2);
      
    printf("%d", a2==a1 && m1==m2 && j2<j1);
    if((a2<a1)||(a2==a1 && m2 <m1) || (a2==a1 && m1==m2 && j2<j1)){
        printf("l'annee la plus ancienne est :%d / %d / %d", m2,j2,a2);
    } 
    else{
        printf("l'annee la plus ancienne est :%d / %d / %d ", m1,j1,a1);
    }
  
    
    return 0;   
}