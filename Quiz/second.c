#include<stdio.h>
#include<stdlib.h>

typedef struct  etd
{
    char cne[20];
    char nom[40];
    char prenom[40];
    char describtion[200];
    float note[4];
    float moy;
}Etudiant;
Etudiant etudiant[30];
int nbEtudiants=0;

void ajouterEtudiant(){
    if(nbEtudiants<30){

        printf("Entrer votre CNE:\n");
        scanf(" %[^\n]%*c",etudiant[nbEtudiants].cne);
        printf("Entrer votre NOM:\n");
        scanf(" %[^\n]%*c",etudiant[nbEtudiants].nom);
        printf("Entrer votre PRENOM:\n");
        scanf(" %[^\n]%*c",etudiant[nbEtudiants].prenom);
        printf("Veuillez ecrire une description a propos l'etudiant: ");
        scanf(" %[^\n]%*c",etudiant[nbEtudiants].describtion);

        nbEtudiants++;
        system("cls");
    }
}

void saisirNotes(){
    int i,numEtd;
    printf("La liste des etudiants:\n");
    for(i=0;i<nbEtudiants;i++){
        printf(" %d- %s %s \n",i+1,etudiant[i].nom,etudiant[i].prenom);
        } 
    printf("Entre le nbr d'etudiant :");
    scanf("%d",&numEtd); 
    numEtd--;

     if( numEtd< 0 || numEtd>nbEtudiants){
        printf("invalide indice\n");
    return; }
    
    printf("Entrer les notes pour \n");
        for ( i = 0; i < 4; i++)
        {
            do{
            printf("note[%d]= ",i+1);
            scanf("%f",&etudiant[numEtd].note[i]);
            
            if(etudiant[numEtd].note[i]<0 || etudiant[numEtd].note[i]>20 )  printf("Attention! La note doit etre entre 0 et 20!!"); 
            } while (etudiant[numEtd].note[i]<0 || etudiant[numEtd].note[i]>20);     
        } 
}

void afficherEtudiants(){
    int i;
    if(nbEtudiants==0){
        printf("Auccun etudiant n'est ajoute.\n");
    
    }
    for ( i = 0; i <nbEtudiants; i++)
    {
        printf("Etudiant num:%d\n",i+1);
        printf("CNE: %s \n",etudiant[i].cne);
        printf("Nom: %s \n",etudiant[i].nom);
        printf("Prenom: %s \n",etudiant[i].prenom);
        printf("Description: %s \n ",etudiant[i].describtion);
    }
}

float afficherBulletin(){

    int n;
    float s=0;
    int i; 

    printf("La liste des etudiants:\n");
    for(i=0;i< nbEtudiants;i++){
        printf(" %d- %s %s \n",i+1,etudiant[i].nom,etudiant[i].prenom);
        } 
    printf("Entrer le nbr d'etudiant : ");
    scanf("%d",&n);n--;
    if(n<0 ||n>=nbEtudiants) {
        printf("Indice introuvable!\n");
        return 0; 
    }    
          for ( i = 0; i <4; i++)
       {
            s=s+etudiant[n].note[i];
           
       }
    printf("la somme des notes est :%.2f \n",s);
    etudiant[n].moy = s/4;
    
    printf("Le bulletin de %s %s : %.2f",etudiant[n].nom,etudiant[n].prenom,etudiant[n].moy);
    return etudiant[n].moy;
}

float calculerMoyenneGeneral(){
    float moyG=0;
    for (int i = 0; i < nbEtudiants; i++)
    {
       moyG =moyG+(etudiant[i].moy/nbEtudiants);
    }
    printf("La moyenne generale est:%.2f\n",moyG);
    return moyG;
}
void TriResultat(){
     int i,j; 
     Etudiant temp;
     for ( i = 0; i < nbEtudiants-1; i++)
     { for ( j = i+1; i < nbEtudiants; j++)
     {
           temp=etudiant[i];
           etudiant[i]=etudiant[j];
           etudiant[j]=temp;

     }  
     for(i=0;i<nbEtudiants;i++){
      printf(" %s %s :%.2f",etudiant[i].nom,etudiant[i].prenom,etudiant[i].moy);
     }  
    }
}
float rechercheDicho(Etudiant etudiant[], float x,int inf,int sup){
  int milieu;
  milieu=(inf+sup)/2;
  while (inf<=sup)
  {
    if(x==etudiant[milieu].moy) 
        return milieu;
    else if (x<etudiant[milieu].moy) 
        sup=milieu-1;
    else   
       inf=milieu+1;
  }
  return -1;
}
int main(){
    int choix,menu;
    
    do{
        printf("\n ***** Menu *****: \n"
        "1. Ajouter un etudiant \n"
        "2. Saisir les notes d'un etudiants \n"
        "3. Afficher tous les etudiants \n"
        "4. Afficher bulletin d'un etudiant \n"
        "5. Calculer la moyenne generale \n"
        "6. Tri des moyennes\n"
        "7. Rechercher \n"
        "0. Quitter \n"
    );

    printf("Entrer vote choix: ");
    scanf("%d",&choix);

    float x;
    int reslt;
    switch (choix)
    {

      case 1:
        ajouterEtudiant();
        system("cls");
        break;
      case 2:
        saisirNotes() ;
        break;
      case 3:
        afficherEtudiants();
        break;
      case 4:
        afficherBulletin();
        break;
      case 5:
        calculerMoyenneGeneral();
        break;  
      case 6:
        TriResultat();
        break;  
      case 7:
        printf("Entrer la moyenne : ");
        scanf("%f",&x);
        reslt = rechercheDicho(etudiant,x,0,nbEtudiants-1);
        if (reslt!=-1)  printf(" %s %s: %.2f\n",etudiant[reslt].nom,etudiant[reslt].prenom,etudiant[reslt].moy);
        else
          printf("Note n'est ps trouvable\n");
        
        break;          
      case 0:
        printf("Au revoir!\n");
        break;                

      default:
        printf("Erreur! Introuvable!!");
        break;
    } 
    
    printf("\n Click 1 if u want the menu\n");
    scanf("%d",&menu);
    if (menu!=1) {printf("Invalide signe"); 
    }
  }while (choix!=0 || menu!=1);

}