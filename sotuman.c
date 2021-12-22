#include<stdio.h>
#include<math.h>

int sochuso(int a)
{
    int dem=0;
    while (a>10)
    {
        a/=10;
        dem++;
    }
    return dem+1;
}
int main()
{
    int m,n,d,tong=0,so;
    scanf("%d",&n);
    m=n;
    d=sochuso(n);
    for(int i=(d-1);i>=0;i--)
    {
        so=m/pow(10,i);
        tong+=pow(so,d);
        m-=so*pow(10,i);
    }
    if(tong==n)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}