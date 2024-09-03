#include<stdio.h>
#define M 100
void main()
{
    int i,m,tableau[M],max,min;
    // Challenge 4 : Trouver le Maximum
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
    max=tableau[0];
    for(i=1;i< m;i++)
    {
        if(max < tableau[i]){
            max=tableau[i];
        }
    }
    printf("le Maximun de Tableau est :%d",max);
    

    
    

}