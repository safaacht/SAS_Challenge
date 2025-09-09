#include<stdio.h>
typedef struct  etd
{
    char cne[20];
    char nom[40];
    char prenom[40];
    float note[4];
    float moy;
}Etudiant;
Etudiant etudiant[30];
int nbEtudiants=0;

void ajouterEtudiant(){
    if(nbEtudiants<30){

        printf("Entrer votre CNE:\n");
        scanf("%s",etudiant[nbEtudiants].cne);
        printf("Entrer votre NOM:\n");
        scanf("%s",etudiant[nbEtudiants].nom);
        printf("Entrer votre PRENOM:\n");
        scanf("%s",etudiant[nbEtudiants].prenom);
        nbEtudiants++;
    }
    // else 
    //    ("Vous avez atteindre le max du nbr d'etudiant.");
    
}


void saisirNotes(){
    int i,index;

    printf("Entre l'indice d'etudiant: ");
    scanf("%d",&index);

    if (index<0 || index>=nbEtudiants){
        printf("Indince non valide.\n");
        return;
    } 
      
         printf("Entrer les notes \n");
        for ( i = 0; i < 4; i++)
        {
            do{
            printf("note[%d]= ",i);
            scanf("%f",&etudiant[index].note[i]);
            
            if(etudiant[index].note[i]<0 || etudiant[index].note[i]>20 )  printf("Attention! La note doit etre entre 0 et 20!!"); 
            } while (etudiant[index].note[i]<0 || etudiant[index].note[i]>20);     
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
    }
    
}

float afficherBulletin(){
    int n;
    float s=0;
    int i; 

    printf("Entrer l'indice d'etudiant: ");
    scanf("%d",&n);
    if(n<0 ||n>nbEtudiants) {
        printf("Indice introuvable!\n");
        return 0; 
    }    
          for ( i = 0; i < 4; i++)
       {
            s=s+etudiant[n].note[i];
           
       }

    etudiant[n].moy = etudiant[n].moy+s/4;
    
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
int main(){
    int choix;
    do{
        printf("\n Menu: \n"
        "1. Ajouter un etudiant \n"
        "2. Saisir les notes d'un etudiants \n"
        "3. Afficher tous les etudiants \n"
        "4. Afficher bulletin d'un etudiant \n"
        "5. Calculer la moyenne generale \n"
        "0. Quitter \n"
    );

    printf("Entrer vote choix: ");
    scanf("%d",&choix);

    switch (choix)
    {

      case 1:
        ajouterEtudiant();
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
      case 0:
        printf("Au revoir!\n");
        break;                

      default:
        break;
    } 
  }while (choix!=0);

}