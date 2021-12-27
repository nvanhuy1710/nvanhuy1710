#include<stdio.h>

long t[30][30],lan=1,s[30][30],tams[30][30];

void nhanmatran(long a[][30],long n,long m,long k)
{
    if(lan<=k)
    {
        if(lan==1)
        {
            for(long i=0;i<n;i++)
            {
                for(long j=0;j<n;j++)
                {
                    t[i][j]=a[i][j];
                    tams[i][j]=a[i][j];
                }
            }
            lan++;
        }
        else
        {
            for(long i=0;i<n;i++)
            {
                for(long j=0;j<n;j++)
                {
                    long tam=0;
                    for(long k=0;k<n;k++)
                    {
                        tam+=(t[i][k]*a[k][j])%m;
                        tams[i][j]=tam;
                    }
                }
            }
            for(long i=0;i<n;i++)
            {
                for(long j=0;j<n;j++)
                {
                    t[i][j]=tams[i][j];
                }
            }
            lan++;
        }
    }
}

void congs(long n,long m)
{
    for(long i=0;i<n;i++)
    {
        for(long j=0;j<n;j++)
        {
            s[i][j]=(s[i][j]+tams[i][j])%m;
        }
    }
}

int main()
{
    long a[30][30];
    long n,k,m;
    scanf("%ld %ld %ld",&n,&k,&m);
    for(long i=0;i<n;i++)
    {
        for(long j=0;j<n;j++)
        {
            scanf("%ld",&a[i][j]);
        }
    }
    for(long i=1;i<=k;i++)
    {
        nhanmatran(a,n,m,k);
        congs(n,m);
    }
    for(long i=0;i<n;i++)
    {
        printf("\n");
        for(long j=0;j<n;j++)
        {
            printf("%ld\t",s[i][j]);
        }
    }
}