#include<stdio.h>
#include<string.h>

struct may
{
    int sotien;
    char loai[50];
    int window;
    int ip;
};

void xoaxuongdong(char x[])
{
    long len=strlen(x);
    if(x[len-1]=='\n')
    {
        x[len-1]='\0';
    }
}
void nhapmaytinh(struct may maytinh[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("may %d:",i);
        printf("\nloai may: ");fflush(stdin);
        fgets(maytinh[i].loai,sizeof(maytinh[i].loai),stdin);xoaxuongdong(maytinh[i].loai);
        printf("\ngia: ");
        scanf("%d",&maytinh[i].sotien);
        printf("\nwindow: ");
        scanf("%d",&maytinh[i].window);
        printf("\ndia chi ip: ");
        scanf("%d",&maytinh[i].ip);
    }
}

void xuatmaytinh(struct may maytinh[],int n)
{
    printf("%-10s \t %-10s \t %-10s \t %-10s","MAY TINH","DIA CHI IP","WINDOW","SO TIEN");
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%-10s \t %-10d \t %-10d \t %-10d",maytinh[i].loai,maytinh[i].ip,maytinh[i].window,maytinh[i].sotien);
        printf("\n");
    }
}

int main()
{
    struct may maytinh[100];
    int n;
    printf("nhap so may tinh:");
    scanf("%d",&n);
    nhapmaytinh(maytinh,n);
    xuatmaytinh(maytinh,n);
}
