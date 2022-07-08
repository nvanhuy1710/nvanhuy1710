#include <stdio.h>

const int MAX = 100;

void swap(float *a, float *b)
{
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

void matrixtranform(float a[][MAX], int row, int column)
{
    int countrow = 0;
    int countcolumn = 0;

    while (countrow < row - 1)
    {
        int tmp = countrow;
        for (int i = tmp; i < row; i++)
        {
            // tìm dòng có phần tử cơ sở ở vị trí = coutcolumn
            if (a[i][countcolumn] != 0)
            {
                // đưa dòng đó lên trên
                for (int j = 0; j < column; j++)
                {
                    swap(&a[countrow][j], &a[i][j]);
                }
                countrow++;
            }
        }
        countcolumn++;
        //neu ma tran la ma tran 0
        if (countcolumn == column)
        {
            return;
        }
    }
}

// bien doi ve bac thang
void transformtoladder(float a[][MAX], int row, int column)
{
    int countrow = 0;
    int countcolumn = 0;
    while (countrow < row - 1)
    {
        // neu phan tu == 0
        while (a[countrow][countcolumn] == 0)
        {
            // tang cot len 1
            countcolumn++;
        }
        if (countcolumn < column)
        {
            // tru di cac phan tu co gia tri khac 0 cung cot
            for (int i = countrow + 1; i < row; i++)
            {
                float tmp = a[i][countcolumn] / a[countrow][countcolumn];
                for (int j = 0; j < column; j++)
                {
                    a[i][j] -= tmp * a[countrow][j];
                }
            }
        }
        countrow++;
        countcolumn = 0;
    }
}

// dem hang ma tran
int checkrank(float a[][MAX], int row, int column)
{
    int rank = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (a[i][j] != 0)
            {
                rank++;
                break;
            }
        }
    }
    return rank;
}

// xuat du lieu ra file matrix.OUT
void fileout(int rank, float a[][MAX], int row, int column)
{
    FILE *fout;
    fout = fopen("matrix.OUT", "w");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            fprintf(fout, "%.2f   ", a[i][j]);
        }
        fprintf(fout, "\n");
    }
    fprintf(fout, "\n");
    fprintf(fout, "Hang cua ma tran vua nhap la: %d", rank);
    fclose(fout);
}

// lay du lieu tu file matrix.INP
void filein(float a[][MAX], int *row, int *column)
{
    FILE *finp;
    finp = fopen("matrix.INP", "r");
    fscanf(finp, "%d\n", row);
    fscanf(finp, "%d\n", column);
    for (int i = 0; i < *row; i++)
    {
        for (int j = 0; j < *column; j++)
        {
            fscanf(finp, "%f ", &a[i][j]);
        }
        printf("\n");
    }
    fclose(finp);
}
void display()
{
    printf("\t__________DO AN LAP TRINH TINH TOAN________\n");
    printf("\tGiang vien: Phan Thanh Tao\n");
    printf("\tDe tai: Tim hang ma tran\n");
    printf("\t|--------------------------------|\n");
    printf("\t|Thanh vien nhom|\tMSSV\t |\n");
    printf("\t|--------------------------------|\n");
    printf("\t|Nguyen Van Huy\t|\t102210010|\n");
    printf("\t|Ngo Duy Tan\t|\t102210022|\n");
    printf("\t|--------------------------------|\n");
    printf("\tVui long vao file matrix.OUT de xem ket qua.\n");
    printf("\tHoac vao file matrix.INP de thay doi ma tran.");
}

int main()
{
    int row, column;
    float a[MAX][MAX];
    filein(a, &row, &column);
    matrixtranform(a, row, column);
    transformtoladder(a, row, column);
    int rank = checkrank(a, row, column);
    fileout(rank, a, row, column);
    display();
}