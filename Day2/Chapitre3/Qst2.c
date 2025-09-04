#include<stdio.h>

int main(){
    int D[2][8]={{8,9,11,12,14,15,19,21},{0,43,19,47,0,45,0,45}};
    int A[2][8]={{10,11,1,15,16,17,21,23},{16,52,31,0,8,55,20,58}};
    int C[8];
    int s=9999;
    int a;
    int H,M,cnvrt;
    printf("Enter une heure de votre choix:\n");
    scanf("%d:%d",&H,&M);
    cnvrt=H*60+M;

    for (int i = 0; i < 8; i++)
    {
        C[i]=D[0][i]*60 +D[1][i];
    }
    for (int i = 0; i < 8; i++)
    {
        int x;
        if(cnvrt<C[i]){
            x=C[i]-cnvrt;
        }
        else{
            x=cnvrt-C[i];
        }
        if(s>x){
           s=x;     //x smmalest than s
           a=i;  }   //showing when we did find the smallest one
    }    
     
    printf("L'heure du depart est %d:%d\n",D[0][a],D[1][a]);
    printf("L'heure d'arriver est %d:%d\n",A[0][a],A[1][a]);

    
    return 0;


}