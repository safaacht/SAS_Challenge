#include<stdio.h>

main(){
    float MP,Ti,T,PM,res;
    printf("Entrer le montant du pret:\n");
    scanf("%f",&MP);
    printf("Entrer le taux d'interet par an:\n");
    scanf("%f",&Ti);
    printf("Entrer le paiment mensuel:\n");
    scanf("%f",&PM);

    T=(Ti/12)/100;
    
    for (int i = 1; i <=3; i++)
    {
        res=(MP-PM)+(MP*T);
        MP=res;
        printf("Solde restant apres le mois %d est : %.2f\n",i,MP);
    }
    return 0;
}