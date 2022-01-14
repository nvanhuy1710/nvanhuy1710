#include<stdio.h>
#include<string.h>

struct xau
{
    char chuoi[20];
}a[100000];

struct xautam
{
    char chuoitam1[20];
    char chuoitam2[20];
}b[100000];

void merge(int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    for(int i=0;i<n1;i++)
    {
        strcpy(b[i].chuoitam1,a[l+i].chuoi);
    }
    for(int j=0;j<n2;j++)
    {
        strcpy(b[j].chuoitam2,a[m+j+1].chuoi);
    }
    i=0;
    j=0;
    k=l;
    while (i<n1 && j<n2)
    {
        int ss=strcmp(b[i].chuoitam1,b[j].chuoitam2);
        if(ss>=0)
        {
            strcpy(a[k].chuoi,b[i].chuoitam1);
            i++;
            k++;
        }
        else
        {
            strcpy(a[k].chuoi,b[j].chuoitam2);
            j++;
            k++;
        }
    }
    while (i<n1)
    {
        strcpy(a[k].chuoi,b[i].chuoitam1);
        i++;
        k++;
    }
    while (j<n2)
    {
        strcpy(a[k].chuoi,b[j].chuoitam2);
        j++;
        k++;
    }
    
}

void mergesort(int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergesort(m+1,r);
        mergesort(l,m);

        merge(l,m,r);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i].chuoi);
    }
    mergesort(0,n-1);
    int dem=1,kt=1;
    for(int i=1;i<n;i++)
    {
        int ss=strcmp(a[i-1].chuoi,a[i].chuoi);
        if(ss==0)
        {
            dem++;
        }
        else
        {
            if(dem==1)
            {
                printf("%s",a[i-1].chuoi);
                kt=0;
                break;
            }
            else
            {
                dem=1;
            }
        }
    }
    if(kt==1)
    {
        
        if(dem==1)
        {
            printf("%s",a[n-1].chuoi);
            kt=0;
        }
        else
        {
            printf("-1");
        }
    }
}