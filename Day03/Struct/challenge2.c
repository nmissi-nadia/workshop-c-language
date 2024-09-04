#include<stdio.h>
#include<string.h>

// Challenge 1 : Définition et Utilisation de Structure
//structure d'une personne
typedef struct 
{
    char nom[20],prenom[20];
    int n;
    int note[20];
}etudiant;
 // la saisie de personne
etudiant Saisi()
{
    etudiant p;
    printf("entrez le nom SVP :");
    gets(p.nom);
    printf("entrez le prenom SVP :");
    gets(p.prenom);
    printf("entrez le nombre des modules SVP :");
    scanf("%d",&p.n);
    for(int i=0;i<p.n;i++)
    {
        
        printf("entrez la note de modules %d SVP :",i+1);
        scanf("%d",&p.note[i]);
    }
    return p;
}
//affichage des infos saisie
void Affichage(etudiant p)
{
    printf("nom -> %s prenom -> %s \n",p.nom,p.prenom);
    for(int i=0;i<p.n;i++)
    {
        printf("la note de modules %d est :%d",i+1,p.note[i]);
        
    }
} 
void main(){
    etudiant p;
    p=Saisi();
    Affichage(p);
}