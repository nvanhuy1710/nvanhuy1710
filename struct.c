#include<stdio.h>

struct thongtin
{
    char ten[20];
    char gioitinh[5];
    int tuoi,ngaysinh,thangsinh,namsinh;
};
int main()
{
    struct thongtin tt;
    printf("nhap ho va ten: ");
    gets(tt.ten);
    printf("\nnhap so tuoi: ");
    scanf("%d",&tt.tuoi);getchar();
    printf("\nnhap ngay sinh: ");
    scanf("%d",&tt.ngaysinh);getchar();
    printf("\nnhap thang sinh: ");
    scanf("%d",&tt.thangsinh);getchar();
    printf("\nnhap nam sinh: ");
    scanf("%d",&tt.namsinh);getchar();
    printf("\ngioi tinh: ");
    gets(tt.gioitinh);
    printf("\n--------------THONG TIN--------------\n");
    printf("ten: %-20s",tt.ten);
    printf("tuoi: %d",tt.tuoi);
    printf("\nngaysinh: %d/%d/%-9d",tt.ngaysinh,tt.thangsinh,tt.namsinh);
    printf("gioi tinh: %s",&tt.gioitinh);
}
