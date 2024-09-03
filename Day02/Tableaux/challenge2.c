#include<stdio.h>
#define M 100
void main()
{
    
    int i,n,tab[M];
    
    // Challenge 2 : Saisie et Affichage des Éléments
    do
    {
      printf("entrer SVP une valeur < 100 :");  
      scanf("%d",&n);
    }while(n>100);
    
    for(i=0;i< n;i++)
    {
        printf("Donnez la valeur de tab[%d]  :",i+1);
        scanf("%d",&tab[i]);
    }
    for(i=0;i< n;i++)
    {
        printf("la valeur de tab[%d] = %d \n",i+1,tab[i]);
    }
}