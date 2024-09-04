// Challenge 4 : Comparaison de Chaînes
#include<stdio.h>
#include<string.h>

void main(){
    char ch1[20],ch2[20],ch3[20];
    printf("entrez SVP une chaine 1 :");
    gets(ch1);
    printf("entrez SVP une chaine 2 :");
    gets(ch2);
    printf("La chaine1 est : %s \n",ch1);
    printf("La chaine3 est : %s \n",ch2);
    if(strcmp(ch1,ch2)==0){
        printf("La chaine1 et la chaine 2 sont egaux  \n");
    }printf("La chaine1 et la chaine 2  ne sont pas  egaux  \n");
    
}