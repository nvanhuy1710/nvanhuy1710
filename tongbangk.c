#include<stdio.h>


long th[22];
long check=0;
long tong(long a[],long n,long k)
{
    long tong=0;
    for(long i=0;i<n;i++)
    {
        tong+=th[i]*a[i];
    }
    if(tong==k)
    {
        check=1;
    }
    return check;
}
void TH(long j,long n, long a[],long k)
{
    for(long i=0;i<=1;i++)
    {
        th[j]=i;
        if(check==1)
        {
            return;
        }
        if(j==(n-1))
        {
            tong(a,n,k);
        }
        else
        {
            TH(j+1,n,a,k);
        }
    }
}
int main()
{
    long a[22],n,k;
    scanf("%ld",&n);
    for(long i=0;i<n;i++)
    {
        scanf("%ld",&a[i]);
    }
    scanf("%ld",&k);
    TH(0,n,a,k);
    if(check==0)
    {
        printf("No");
    }
    else
    {
        printf("Yes");
    }
}