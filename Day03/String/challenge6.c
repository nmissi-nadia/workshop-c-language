#include<stdio.h>
#include<string.h>
// Challenge 6 : Compte des Occurrences d'un Caractère
void main(){
    char ch1[20];
    int i,j=0;
    char c;
    printf("entrez SVP une chaine 1 :");
    gets(ch1);
    printf("entrez SVP une caractere :");
    scanf("%c",&c);
    for(i = 0;i<strlen(ch1);i++)  {
        if(ch1[i]==c){
            j++;

        }
    }
    printf("i= %d \n",j);

}