#include<stdio.h>

int dodaiso(char so[])
{
    int len=0;
    while(so[len]!='\0')
    {
        len++;
    }
    return len;
}

int main()
{
    char so1[101];
    char so2[101];
    scanf("%s %s",&so1,&so2);
    int mangso1[100];
    int mangso2[100];
    int dem1=0,dem2=0;
    int len1=dodaiso(so1);
    int len2=dodaiso(so2);
    int lentich=len1+len2;
    for(int i=0;i<len1;i++)
    {
        mangso1[i]=(int)(so1[i]-'0');
    }
    for(int i=0;i<len2;i++)
    {
        mangso2[i]=(int)(so2[i]-'0');
    }
    for(int i=0;i<len1;i++)
    {
        if(mangso1[i]==0)
        {
            dem1++;
        }
    }    
    for(int i=0;i<len2;i++)
    {    
        if(mangso2[i]==0)
        {
            dem2++;
        }
    }    
    if(dem1==len1 || dem2==len2)
    {
        printf("0");
    }
    else
    {
        int tich[202];
        for(int i=0;i<203;i++)
        {
            tich[i]=0;
        }
        int tichtungso[202];
        int tichtungcai=0,nho=0;
        for(int j=len2-1;j>=0;j--)
        {
            for(int i=0;i<203;i++)
            {
                tichtungso[i]=0;
            }
            int vt=202;
            vt-=len2-(j+1);
            for(int i=len1-1;i>=0;i--)
            {
                tichtungcai=(mangso1[i])*(mangso2[j])+nho;
                nho=tichtungcai/10;
                tichtungcai=tichtungcai%10;
                tichtungso[vt]=tichtungcai;
                vt--;
            }
            if(nho!=0)
            {
                tichtungso[vt]=nho;
                nho=0;
            }
            int nhotong=0;
            for(int i=202;i>=0;i--)
            {
                int tong=tich[i];
                tong=tong+tichtungso[i]+nhotong;
                nhotong=tong/10;
                tong=tong%10;
                tich[i]=tong;
            }
        }
        if(tich[202-lentich+1]==0)
        {
            lentich--;
        }
        for(int i=202-lentich+1;i<=202;i++)
        {
            printf("%d",tich[i]);
        }
    }
}
