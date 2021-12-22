#include<stdio.h>

int lenchuoi(char chuoi[])
{
    int i=0;
    while(chuoi[i]!='\0')
    {
        i++;
    }
    return i;
}

int main()
{
    int q;
    scanf("%d",&q);
    for(int p=0;p<q;p++)
    {
        char chuoi[200];
        char ngoac[200];
        scanf("%s",&chuoi);
        int len=lenchuoi(chuoi),k=0;
        for(int i=0;i<len;i++)
        {
            ngoac[i]=(chuoi[i]);
        }
        for(int i=0;i<len;i++)
        {
            if(ngoac[i]=='(')
            {
                int dem=i;
                for(int j=i+1;j<len;j++)
                {
                    if(ngoac[j]==')')
                    {
                        dem=j;
                        break;
                    }
                }
                if(ngoac[dem]==')')
                {
                ngoac[i]='a';
                ngoac[dem]='a';
                }
                if(ngoac[i]!='a')
                {
                    k=1;
                    printf("NO\n");
                    break;
                }
            }
            if(ngoac[i]==')')
            {
                k=1;
                printf("NO\n");
                break;
            }
        }
        /*for(int i=0;i<len;i++)
        {
            printf("%c",ngoac[i]);
        }*/
        if(k==0)
        {
            printf("YES\n");
        }
    }
}