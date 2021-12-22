#include<stdio.h>

int main()
{
    long n,diem=1;
    long a[100000];
    long kq[100000],chot[100000],vitri[100000];
    scanf("%ld",&n);
    for(long i=0;i<n;i++)
    {
        scanf("%ld",&a[i]);
    }
    chot[0]=a[0];
    vitri[0]=0;
    for(long i=1;i<n-1;i++)
    {
        if(a[i]>a[i+1] || a[i]==a[i+1] || i==n-2)
        {
            chot[diem]=a[i];
            vitri[diem]=i;
            diem++;
        }
    }
    for(long i=n-1;i>=0;i--)
    {
        
    
        long k=i;
        for(long j=diem-1;j>=0;j--)
        {
            if(vitri[j]<i)
            {
                if(a[i]>chot[j])
                {
                    kq[i]+=k-vitri[j];
                    k=vitri[j];
                }
                else
                {
                    kq[i]+=k-vitri[j];
                    break;
                }
            }
        }
        
    }
    for(long i=0;i<n;i++)
    {
        printf("%ld\t",kq[i]);
    }
}