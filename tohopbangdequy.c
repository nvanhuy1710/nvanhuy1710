#include<stdio.h>
int tohop(int k,int n)
{
    if(k==n||k==0)
    {
        return 1;
    }
    if (k==1)
    {
        return n;
    }
    return tohop(k-1,n-1)+ tohop(k,n-1);
}
int main()
{
    int a,b;
    do
    {
        /* code */printf("nhap k va n (k<=n): ");
    scanf("%d",&a);
    scanf("%d",&b);
    } while (/* condition */a>b);
    
    printf("ket qua la: %d",tohop(a,b));
   
    
    
}