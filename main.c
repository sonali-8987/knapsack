#include <stdio.h>
#include <stdlib.h>
void knapsack(float [],float [],float [],int ,float );
float w[10],p[10],fraction[10];
int main()
{
    int n,i,j;
    float m,temp1,temp2,temp3;
    printf("\nenter capacity of bag:");
    scanf("%f",&m);
    printf("\nenter no of object:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    printf("\nenter weights of object:\nob%d:",i+1);
        scanf("%f",&w[i]);
    printf("\nenter profit of object:\nob%d:",i+1);
        scanf("%f",&p[i]);
    fraction[i]=p[i]/w[i];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<=n-i-1;j++)
        {
          if(fraction[j]<fraction[j+1])
          {
            temp1=fraction[j];
            fraction[j]=fraction[j+1];
            fraction[j+1]=temp1;

            temp2=w[j];
            w[j]=w[j+1];
            w[j+1]=temp2;

            temp3=p[j];
            p[j]=p[j+1];
            p[j+1]=temp3;

          }
        }
    }
    knapsack(w,p,fraction,n,m);
    return 0;

}

void knapsack(float w[],float p[],float fraction[],int num,float c)
{
   int i;
   float profit=0;
   for(i=0;i<num;i++)
   {
       if(c>0 && w[i]<=c)
       {
         c=c-w[i];
         profit=profit+p[i];
       }
       else
        break;
   }
       if(c>0)
        profit=profit+((c/w[i])*p[i]);
        printf("\ntotal profit:%.2f",profit);

}
