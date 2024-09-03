#include<stdio.h>
#define M 100
void main()
{
    int i,j,c,m,tableau[M],produit=1;
  
    // Challenge 7 : Tableau en Ordre Croissant
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
    printf("Tableau avant tri ");
   for(i=0;i< m;i++)
    {
        printf("la valeur de Tableau[%d] = %d \n",i+1,tableau[i]);
    }

for(i=0;i<m-1;i++)
    for(j=i+1;j<m;j++)
        if ( tableau[i] > tableau[j] ) {
            c = tableau[i];
            tableau[i] = tableau[j];
            tableau[j] = c;
        }
        printf("Tableau apres tri \n");
         for(i=0;i< m;i++)
    {
        printf("la valeur de Tableau[%d] = %d \n",i+1,tableau[i]);
    }
        }