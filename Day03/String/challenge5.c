#include<stdio.h>
#include<string.h>

void main(){
char ch1[100], inver[100];
    int t, i, j;
 
    printf(" Entrez une chaine de caractere :  ");
    gets(ch1);
    
    j = 0;
    t = strlen(ch1);
 
    inver[t] = '\0'; 
    for (i = t - 1; i >= 0; i--)
    {
      inver[j++] = ch1[i];
    }
    inver[i] = '\0';
 
    printf(" Chaine  inverser = %s", inver);
}