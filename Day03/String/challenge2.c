#include<stdio.h>
#include<string.h>

void main(){
    // Challenge 2 : Longueur de la Chaîne
     char chaine[20];
    printf("entrez SVP une chaine :");
    gets(chaine);
    printf("La chaine est : %s est la longeur de cette chaine est %d : \n",chaine,strlen(chaine));
}