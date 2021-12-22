#include<stdio.h>
int giaithua(int a)
{
    int s=1;
    for(int i=1;i<=a;i++)
    {
        s*=i;
    }
    return s;

}
int tohop(int k,int n)
{
    return giaithua(n)/(giaithua(k)*giaithua(n-k));
}

int main()
{
    for(int i=0;i<7;i++)
    {
        for(int k=i;k<(12-i);k++)
        {
            printf(" ");
        }
        for(int j=0;j<=i;j++)
        {
            printf("%4d",tohop(j,i));
        }
        printf("\n");
    }

}