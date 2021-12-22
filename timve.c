#include<stdio.h>

long timve(long v[],long sotien,long n)
{
    long trai=0,tam=0;
    long phai=n-1;
    if(v[0]>sotien)
    {
        return -1;
    }
    while (trai<=phai)
    {
        long giua=(trai+phai)/2;
        if(v[giua]==sotien)
        {
            return giua;
        }
        else if(v[giua]>sotien)
        {
            phai=giua-1;
        }
        else
        {
            //trai=giua+1;
            if(v[giua]>tam && v[giua]<sotien)
            {
                tam=giua;
                //printf("%ld\n",tam);
            }
            trai=giua+1;
        }
    }
    return tam;
}

int main()
{
    long v[100000];
    long n,m;
    scanf("%ld",&n);
    for(long i=0;i<n;i++)
    {
        scanf("%ld",&v[i]);
    }
    scanf("%ld",&m);
    for(int i=0;i<m;i++)
    {
        long sotien,vitri;
        scanf("%ld",&sotien);
        vitri=timve(v,sotien,n);
        if(vitri==-1)
        {
            printf("-1\n");
        }
        else
        {
            printf("%ld\n",v[vitri]);
        }
    }
}