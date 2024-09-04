// Mini-Projet : Système de Gestion de Contacts
#include<stdio.h>
#include<string.h>
//le champs de structure de 
typedef struct {
    char nom[20],num[20],adresse[20];
}Contact;

    Contact carnet[100];
    int taille =0;

// fonction qui saisir  un contact 
void Ajouter()
{
    int l;
 printf("Combien de contact vous voulez ajouter \n");
 scanf("%d",&l);
for(int i=0;i<l;i++){
    printf("Entrez le nom du nouvelle nom :");
    scanf("%s",carnet[i].nom);
    printf("Entrez son numero :");
    scanf("%s",carnet[i].num);
    printf("Entrez son adresse mail :");
    scanf("%s",carnet[i].adresse);
    taille++;
}

}
//Ajouter un contact a un carnet
// void Ajouter_car(Carnet re)
// { int i;

//     for ( i = 0; i < re.taille; i++)
//     {
//         /* code */
//     }
//     re.con[i]=Ajouter();
//     re.taille++;
// }
// Afficher un seul contact
/*void Afficher(Contact c){
printf(" Nom : %s -> Num : %s -> Adresse :% s \n",c.nom,c.num,c.adresse);
}*/
//Afficher un carnet 
void Afficher_carnet()
{
    int i;
    for ( i = 0; i < taille; i++)
    {
        printf(" Nom : %s -> Num : %s -> Adresse :% s \n",carnet[i].nom,carnet[i].num,carnet[i].adresse);
    }
    
}
// Gestion des contact 
// void gestion(){
//     int choix;
//     while(choix != 0){
//         printf("---------------------------Menu---------------------- ");
//         printf("Si vous voulez ajouter un contact entrez 1 :\n "
//         "Si vous voulez afficher les contacts entrez 2 :\n"
//         "Si vous voulez rechercher a un contact entrez 3 :\n"
//         "Si vous voulez supprimer un contact entrez 4 :\n"
//         "Si vous voulez quitter le menu entrez 0 :\n");
//         scanf("%d",&choix);
//         switch (choix)
//         {
//         case 1:
//             Ajouter();
//             break;
//         // case 2:
//         //     Afficher_carnet();
//         //     break;
//         // case 3:
//         //     /* code */
//         //     break;
//         // case 4:
//         //     /* code */
//         //     break;
        
//         default:
//             printf("choix impossible");
//             break;
//         }
//     }
// }
 void main(){
    // Contact c;
     int choix;
    while(choix != 0){
        printf("---------------------------Menu---------------------- ");
        printf("Si vous voulez ajouter un contact entrez 1 :\n "
        "Si vous voulez afficher les contacts entrez 2 :\n"
        "Si vous voulez rechercher a un contact entrez 3 :\n"
        "Si vous voulez supprimer un contact entrez 4 :\n"
        "Si vous voulez quitter le menu entrez 0 :\n");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1:
            Ajouter();
            break;
        case 2:
            Afficher_carnet();
            break;
        // case 3:
        //     /* code */
        //     break;
        // case 4:
        //     /* code */
        //     break;
        
        default:
            printf("choix impossible");
            break;
         } 
         }

 }