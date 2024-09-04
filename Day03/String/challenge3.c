#include<stdio.h>
#include<string.h>
// Challenge 3 : Concaténation de Chaînes
void main(){
    char ch1[20],ch2[20],ch3[20];
    printf("entrez SVP une chaine 1 :");
    gets(ch1);
    printf("entrez SVP une chaine 2 :");
    gets(ch2);
    printf("La chaine1 est : %s \n",ch1);
    printf("La chaine3 est : %s \n",ch2);
    
    strcat(ch1,ch2);
    printf("La chaine concatener est : %s",ch1);
}