#include<stdio.h>
#define MAX_NOTES 100

float notes[MAX_NOTES];
int nbNotes=0;   //la taille

void saisir_notes(float notes[],int *nbNotes){
    int i;
    printf("Entrer le nbr des notes:  ");
    scanf("%d",nbNotes);
    printf("Remplisser le tableau:\n");

     for(i=0;i<*nbNotes;i++){
       do{
        printf("note[%d]= ",i);
        scanf("%f",&notes[i]); 

        if (notes[i]<0 || notes[i]>20) printf("Attention! Les notes doivent etre entre 0 et 20 !!");
       
       } while (notes[i]<0 || notes[i]>20);
    }
}

void afficher_notes(float notes[],int nbNotes){
    int i;
    for ( i = 0; i < nbNotes; i++)
    {
        printf(" notes[%d] :%.2f \n",i,notes[i]);
    }
    
}

float calculerMoyenne(float notes[],int nbNotes){
    float s=0,M;
    int i;
    for ( i = 0; i < nbNotes; i++)
    {
        s=s+notes[i];
    }

     M=s/nbNotes;
    printf("la moyenne est :%.2f \n",M);
    return M;
}

float trouverMax(float notes[],int nbNotes,int *idxMax){
    int i;
    float max;
    max=notes[0];
    for ( i = 1; i < nbNotes; i++)
    {
        if(max<notes[i]){
            max=notes[i];
            *idxMax=i; 
        }
        
    }
    printf("Le max est : %.2f a l'index :%d\n",max,*idxMax);
    
    return max;
}

float trouverMin(float notes[],int nbNotes,int *idxMin){
    int i;
    float min;
    min=notes[0];

    for ( i = 1; i < nbNotes; i++)
    {
        if(min>notes[i]){
            min=notes[i]; 
            *idxMin=i; 
        }
    }
    printf("Le min est : %.2f a l'index :%d\n",min,*idxMin);
    
    return min;
}

int compterAdmis(float notes[],int nbNotes){
    int i;
    int a=0;    //compteur des admis
    for ( i = 0; i < nbNotes; i++)
    {
        if(notes[i]>=10){
            printf("Vous etes admis.\n");
            a++;
        } 
    }
    return a;
    
}

int compterNonAdmis(float notes[],int nbNotes){
    int i;
    int b=0;    //compteur des non admis
    for ( i = 0; i < nbNotes; i++)
    {
        if(notes[i]<10){
            printf("Malheureusement !Vous n'etes pas admis.\n");
            b++;
        } 
    }
    return b;
    
}

int ajouterNote(float notes[],int *nbNotes,float valeur){
    if(*nbNotes>= MAX_NOTES){
        printf("Vous pas ajouter plus de notes!\n");
        return 0;
    }
    notes[*nbNotes]=valeur;
    (*nbNotes)++;
    
    printf("la note ajoutee : %.2f",valeur);
   
    return 1;
}

int  modifierNote(float notes[],int nbNotes,int idx, float nv){
    
    if (idx<0 || idx>=nbNotes){
        printf("Index inacceptable \n");
        return 0;
    }

    notes[idx]=nv;

    printf("La note a l'index %d est modifiee %.2f \n",idx,nv);
    return 1;
}

int supprimerNote(float notes[],int *nbNotes,int idx){
    int i;
    printf("Entrez l'index de la note : ");
    scanf("%d", &idx);

    if (idx<0 || idx>= *nbNotes){
        printf("Index inacceptable \n");
        return 0;
    }
    for(i=idx;i<*nbNotes-1;i++){
        notes[i]=notes[i+1];
    }

    (*nbNotes)--;
    printf("Note supprimee avec succes.\n");

    return 1;
}

int main(){
    int choix;
    int idxMin,idxMax,idx;
    float nv,valeur;
    do{
    printf("\n Menu:\n"
        "1. Saisir les notes\n"
        "2. Afficher les notes \n"
        "3. Statistiques\n"
        "4. Ajouter note\n"
        "5. Modifier une note \n"
        "6. Supprimer une note\n"
        "0. Quitter\n");
    scanf("%d",&choix);
    switch (choix)
    {
    case 1:
        saisir_notes(notes,&nbNotes);
        break;
    case 2:
        afficher_notes(notes,nbNotes);
        break;   
    case 3:
        printf("Moyenne : %.2f\n", calculerMoyenne(notes, nbNotes));
        printf("Max : %.2f index %d\n", trouverMax(notes, nbNotes, &idxMax), idxMax);
        printf("Min : %.2f index %d\n", trouverMin(notes, nbNotes, &idxMin), idxMin);

        printf("Nombre d'admis : %d\n", compterAdmis(notes, nbNotes));
        printf("Nombre de non admis : %d\n", compterNonAdmis(notes, nbNotes));  
        break;  
    case 4:
         printf("Entrez la note a ajouter : ");
        scanf("%f", &valeur);
        ajouterNote(notes,&nbNotes,valeur);
        break;  
    case 5:
        printf("Entrez l'index de la note a modifier : ");
        scanf("%d", &idx);
        printf("Entrez la nouvelle valeur : ");
        scanf("%f", &nv);
        modifierNote(notes,nbNotes,idx,nv);
        break;  
    case 6:
        supprimerNote(notes,&nbNotes,idx);
        break;  
    case 0:
        printf("Au revoir !\n");
        break;                  
    default:
        printf("Erreur! Not found!!");
        break;
    }
    }while (choix!=0);

   return 0;    
}
