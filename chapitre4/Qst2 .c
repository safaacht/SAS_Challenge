#include<stdio.h>
#include<math.h>

main(){
  const float Pi=3.14;
  float V,r;
  
  printf("Entrer la valeur du rayon\n");
  scanf("%f",&r);

  V= (4.0f/3.0f)*Pi*pow(r,3);

  printf("Le volume du sphere est :%.2f\n",V);
  return 0 ;
}