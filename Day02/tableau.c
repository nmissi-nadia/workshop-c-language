#include<stdio.h>
 
void main()
{
    int T[]= {1,2,3,4,5};
    int i,n,tab[100];
    // Challenge 1 : Initialisation et Affichage
    // for(i=0;i< 5;i++)
    // {
    //     printf("la valeur de T[%d] = %d \n",i+1,T[i]);
    // }
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
    // Challenge 3 : Somme des Éléments
    
}