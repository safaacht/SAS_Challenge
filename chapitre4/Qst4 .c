#include<stdio.h>

main(){
    float MT,taxe;
    
    printf("Entrer un montant en dollars:\n");
    scanf("%f",&MT);

    taxe=MT*0.05;
    MT=MT+taxe;

    printf("Le montant avec les texes est : %.2f\n",MT);
    return 0;

}
