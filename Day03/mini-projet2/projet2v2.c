#include <stdio.h>
#include <string.h>

// Définition de la structure Contact
typedef struct {
    char nom[20];
    char num[20];
    char adresse[20];
} Contact;

// Définition de la structure Carnet
typedef struct {
    Contact con[100];
    int taille;
} Carnet;

// Fonction pour saisir un contact
Contact Ajouter() {
    Contact c;
    printf("Entrez le nom du nouveau contact : ");
    fgets(c.nom, sizeof(c.nom), stdin);
    c.nom[strcspn(c.nom, "\n")] = '\0'; 

    printf("Entrez son numero : ");
    fgets(c.num, sizeof(c.num), stdin);
    c.num[strcspn(c.num, "\n")] = '\0';

    printf("Entrez son adresse mail : ");
    fgets(c.adresse, sizeof(c.adresse), stdin);
    c.adresse[strcspn(c.adresse, "\n")] = '\0';

    return c;
}

// Ajouter un contact à un carnet
void Ajouter_car(Contact c, Carnet *re) {
    re->con[re->taille] = c;
    re->taille++;
}

// Afficher un seul contact
void Afficher(Contact c) {
    printf("Nom : %s -> Num : %s -> Adresse : %s\n", c.nom, c.num, c.adresse);
}

// Afficher un carnet
void Afficher_carnet(Carnet re) {
    int i;
    for ( i = 0; i < re.taille; i++) {
        Afficher(re.con[i]);
    }
    printf("\n");
}
// modification des infoemations d un contact
void modification(Carnet *re,char nom[20])
{
    int i,j=0;
    char nul[20],adro[20];
    for ( i = 0; i < re->taille; i++) {
        if(strcmp(re->con[i].nom,nom)==0){
            printf("Donnez la nouvelle numero :");
            scanf("%s",nul);
            printf("Donnez la nouvelle adresse :");
            scanf("%s",adro);
           
            strcpy(re->con[i].num,nul);
            strcpy(re->con[i].adresse,adro);
            //  printf("--------------");
            // printf("%s",re->con[i].num);
            // printf("%s",re->con[i].adresse);
            // printf("--------------");
        j=1;
        }
        
    }
    if(j==0){
        printf("le nom n'existe pas   !!!!!");
    }
}
//recherche d'un contact
void recherche(Carnet re,char nom[20])
{
  int i,j=0,pos;
    char nul[20],adro[20];
    for ( i = 0; i < re.taille; i++) {
        if(strcmp(re.con[i].nom,nom)==0){
        j=1;
        pos=i;
        }
       
    }
    if(j==1){
        printf("le nom existe et ces cordonnees sont :  \n");
        printf("Nom : %s -> Num : %s -> Adresse : %s\n", re.con[pos].nom, re.con[pos].num, re.con[pos].adresse);
    }
}
//suppression des contacts du carnet
Carnet suppresion(Carnet *re,char nom[20])
{
    int i,j=0,k;
    char nul[20],adro[20];
    for ( i = 0; i < re->taille; i++) {
        if(strcmp(re->con[i].nom,nom)==0){
            for ( k = i; k < re->taille; k++) {   
                re->con[k]=re->con[k + 1];
            }
            re->taille--;
        j=1;
        }
        
    }
    if(j==0){
        printf("le nom n'existe pas   !!!!!");
    }
    return *re;
}
// Gestion des contacts
void gestion() {
    int choix = -1;
    Carnet re;
    char sky[20];
    re.taille = 0;

    while (choix != 0) {
        printf("---------------------------Menu----------------------\n");
        printf("Si vous voulez ajouter un contact entrez 1 :\n");
        printf("Si vous voulez afficher les contacts entrez 2 :\n");
        printf("Si vous voulez modifier un contact entrez 3 :\n");
        printf("Si vous voulez supprimer un contact entrez 4 :\n");
        printf("Si vous voulez rechercher a un contact entrez 5 :\n");
        printf("Si vous voulez quitter le menu entrez 0 :\n");
        scanf("%d", &choix);
        getchar(); 

        switch (choix) {
            case 1:
                Ajouter_car(Ajouter(), &re);
                break;
            case 2:
                Afficher_carnet(re);
                break;
            case 3:
                printf("entrez le nom du contact peut modifier :");
                fgets(sky, sizeof(sky), stdin);
                sky[strcspn(sky, "\n")] = '\0'; 
                modification(&re,sky);
                break;
            case 4:
                printf("entrez le nom du contact peut modifier :");
                fgets(sky, sizeof(sky), stdin);
                sky[strcspn(sky, "\n")] = '\0'; 
                re=suppresion(&re,sky);
                break;
            case 5:
                printf("entrez le nom du contact peut rechercher :");
                fgets(sky, sizeof(sky), stdin);
                sky[strcspn(sky, "\n")] = '\0'; 
                recherche(re,sky);
                break;
            default:
                printf("Fin de saisie.\n");
                break;
        }
    }
}

void main() {
    gestion();
    
}
