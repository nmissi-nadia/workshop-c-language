// Challenge 9 : Suppression des Espace
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void main(){
    int i,k;
    char chaine[20];
    printf("entrez SVP une chaine :");
    gets(chaine);
    printf("La chaine est : %s \n",chaine);
    for(i = 0;i<strlen(chaine);i++)  {
        if(chaine[i]==' '){
            for ( k = i; k < strlen(chaine)-1; k++)
            {
                chaine[k]=chaine[k+1];
            }
            
        }
    }
    printf("La chaine est : %s",chaine);
}
