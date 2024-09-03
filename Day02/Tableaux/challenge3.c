#include<stdio.h>
#define M 100
void main()
{
    int i,m,tableau[M],somme=0;
  
    // Challenge 3 : Somme des Éléments
     do
    {
      printf("entrer SVP une valeur < 100 :");  
      scanf("%d",&m);
    }while(m>100);
    
    for(i=0;i< m;i++)
    {
        printf("Donnez la valeur de tab[%d]  :",i+1);
        scanf("%d",&tableau[i]);
    }
    for(i=0;i< m;i++)
    {
        somme+=tableau[i];
    }
    printf("la somme = %d",somme);
}