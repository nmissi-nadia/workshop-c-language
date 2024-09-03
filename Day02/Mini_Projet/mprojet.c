
#include <stdio.h>
#include <string.h>

// Ajouter un livre au stock 
void Ajouter(char Titre[][100], char auteur[][100], double *prix, int *qte, int *i) {
    char titree[100], aut[100];
    double pr;
    int qt;

    printf("Entrer le titre: ");
    scanf("%s", titree);
    strcpy(Titre[*i], titree);

    printf("Entrer le NOM DU auteur: ");
    scanf("%s", aut);
    strcpy(auteur[*i], aut);

    printf("Entrer le Prix: ");
    scanf("%lf", &pr);
    prix[*i] = pr;

    printf("Entrer la quantite de livre: ");
    scanf("%d", &qt);
    qte[*i] = qt;
}
// Afficher tous les livres disponibles.
void Afficher(char Titre[][100], char auteur[][100], double *prix, int *qte, int *i)
{
    int j;
    if(*i==0){
        printf("le stock est vide");
    }else{
        for(j=0;j<*i;j++){
            printf("le titre est %s ,l'auteur est %s ,le prix est %lf,la quantite est %d \n",Titre[j],auteur[j],prix[j],qte[j]);
        }
    }
}
//Mettre à Jour la Quantité d'un Livre
void Maj(char Titre[][100],char* nom, int *qte,int nvqt,int *i){
    int j;
    for(j=0;j<*i;j++){
        if(strcmp(Titre[j],nom)==0){
            qte[j]=nvqt;
        }
    }
}
//Supprimer un Livre du Stock

void suppression(char Titre[][100], char auteur[][100], double *prix, int *qte, int *i, char nom[20]) {
    int j, k;
    for (j = 0; j < *i; j++) {
        if (strcmp(Titre[j], nom) == 0) {
            
            for (k = j; k < *i - 1; k++) {
                strcpy(Titre[k], Titre[k + 1]);
                strcpy(auteur[k], auteur[k + 1]);
                prix[k] = prix[k + 1];
                qte[k] = qte[k + 1];
            }

            (*i)--;
            printf("Le livre '%s' a été supprimé du stock.\n", nom);
            return;
        }
    }
    printf("Le livre '%s' n'a pas été trouvé dans le stock.\n", nom);
}
// Afficher le Nombre Total de Livres en Stock
int nb_totale(int quan[100],int *i)
{
    int somme=0,j;
    for(j=0;j< *i;j++)
                {
                    somme+=quan[j];
                }
    return somme; 
}
void main() {
    int choix ;
    int i = 0,j,somme;
    char titre[100][100];
    char auteur[100][100];
    double prix[100];
    int qte[100],nvqt;
    char titremaj[20],titresup[20];

    while (choix != 0) {
        printf("Si vous pouvez ajouter un livre entrez 1,\nSi vous pouvez afficher un stock entrez 2 \n Si vous pouvez Mettre a Jour la Quantite d'un Livre entrez 3 \nSi vous pouvez supprimer un stock entrez 4 \nSi vous pouvez Afficher le Nombre Total de Livres en Stock entrez 5 \n si vous pouvez sortir entrez 0: ");
        scanf("%d", &choix);
        switch(choix ) {
            case 1:
            Ajouter(titre, auteur, prix, qte, &i);
            i++;
            break;
            case 2:
            Afficher(titre, auteur, prix, qte, &i);
            break;
            case 3:
            printf("entrer le titre du livre a mis a jour :");
            scanf("%s",&titremaj);
            printf("entrer la qantite a mis a jour :");
            scanf("%d",&nvqt);
            Maj(titre,titremaj,qte,nvqt,&i);
            break;
            case 4:
            printf("entrer le titre du livre a mis a jour :");
            scanf("%s",&titresup);
            suppression(titre, auteur, prix, qte, &i,titresup);
            break;
            case 5:
                somme=nb_totale(qte,&i);
                printf("le nombre totale de livre = %d \n",somme);
            break;
        }
    }

    
}
