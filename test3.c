#include<stdio.h>

int main()
{
    long h[100000];
    long kq[100000];
    long n;
    scanf("%ld",&n);
    for(long i=0;i<n;i++)
    {
        scanf("%ld",&h[i]);
    }
    for(long i=n-1;i>=0;i--)
    {
        long vitri=i,dem=0;
        for(long j=vitri-1;j>=0;j--)
        {
            dem++;
            if(h[j]>=h[i])
            {
                break;
            }
            //dem++;
        }
        kq[i]=dem;
    }
    for(long i=0;i<n;i++)
    {
        printf("%ld\t",kq[i]);
    }
}