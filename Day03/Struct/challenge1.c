#include<stdio.h>
#include<string.h>

// Challenge 1 : Définition et Utilisation de Structure
//structure d'une personne
typedef struct 
{
    char nom[20],prenom[20];
    int age;
}personne;
 // la saisie de personne
personne Saisi()
{
    personne p;
    printf("entrez le nom SVP :");
    gets(p.nom);
    printf("entrez le prenom SVP :");
    gets(p.prenom);
    printf("entrez l\'age SVP :");
    scanf("%d",&p.age);
    return p;
}
//affichage des infos saisie
void Affichage(personne p)
{
    printf("nom -> %s prenom -> %s age -> %d\n",p.nom,p.prenom,p.age);
} 
void main(){
    personne p;
    p=Saisi();
    Affichage(p);
}