#include<stdio.h>

int count(int N){
    int c=0;
    if(N==0) return 1;
    while(N!=0){
        N/=10;
        c++;
    }
    return c;
}
int main(){
    int GS1,Ig,code,Num_Artcl,Chiff_ctrl;
    do
    {
        printf("Entrer l'ISBN:\n");
        scanf("%d - %d - %d - %d - %d",&GS1,&Ig,&code,&Num_Artcl,&Chiff_ctrl);

        if(GS1 != 978 && GS1 != 979) printf("Erreur! \n");

    } while (GS1 != 978 && GS1 != 979);
     printf("Prefixe GS1 : %d\n",GS1);
        printf("Identifiant de grp : %d\n",Ig);
        printf("Code d'editeur : %d\n",code);
        printf("Num d'arrticle : %d\n",Num_Artcl);
        printf("Chiffre de controle : %d\n",Chiff_ctrl);

    // printf("COUNT : %d\n",count(GS1));
    // printf("COUNT : %d\n",count(Ig));
    // printf("COUNT : %d\n",count(code));
    // printf("COUNT : %d\n",count(Num_Artcl));
    // printf("COUNT : %d\n",count(Chiff_ctrl));
    
    if(count(GS1)+count(Ig)+count(code)+count(Num_Artcl)+count(Chiff_ctrl)>13) printf("Erreur ! Le max est 13\n");
     int s=count(GS1)+count(Ig)+count(code)+count(Num_Artcl)+count(Chiff_ctrl);
     printf("Ur count is =%d\n",s);
    return 0;
}