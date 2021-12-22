#include<stdio.h>

int main()
{
   int n,m=1;
   do
   {
      /* code */printf("nhap n (0<n<=10): ");
      scanf("%d",&n);
   } while (/* condition */n<=0||n>10);
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=i;j++)
      {
         printf("%4d",m);
         m++;
      }
      printf("\n");
   }
   
   
}