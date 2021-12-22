#include<stdio.h>

int main()
{
    long m,n,a,b,sodong1,sodong2,solan,kc;
    scanf("%ld %ld %ld %ld",&n,&m,&a,&b);
    sodong1=(a-1)/m+1;
    sodong2=(b-1)/m+1;
    kc=sodong2-sodong1;
    if(m==1)
    {
        solan=1;
    }
    else
    {
    if(kc==0)
    {
        solan=1;
    }
    if(kc==1)
    {
        if(a%m==1 && (b%m==0 || b==n))
        {
            solan=kc;
        }
        else
        {
            solan=kc+1;
        }
    }
    if(kc>1)
    {
    if(((b%m+1==a%m) && (b%m!=0)) || (a%m==0 && b%m==m-1))
    {
        solan=2;
    }
    else
    {
    if(a%m==1 && (b==n || b%m==0))
    {
        solan=1;
    }
    if(a%m==1 && b!=n && b%m!=0)
    {
        solan=2;
    }
    if(a%m!=1 && (b==n || b%m==0))
    {
        solan=2;
    }
    if (a%m!=1 && b!=n && b%m!=0)
    {
        solan=3;
    }
    }
    }
    }
    printf("%ld",solan);
}