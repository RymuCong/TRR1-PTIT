/*
Bài 3.3. Sinh tất cả các tổ hợp chập k của n phần từ 1, 2, ..., n
Input format:

- Đọc k, n từ bàn phím

Output format:

- In ra các tổ hợp chập k của n phần từ 1 .. n, các phần tử của 1 tổ hợp cách nhau một vài khoảng trống

- Mỗi tổ hợp trên 1 dòng

Ví dụ: các tổ hợp chập 2 của 3 phần tử:

1 2

1 3

2 3
*/

#include<stdio.h>

int SinhTH (int n, int k, int HT[], int TT[])
{
    int i, cauhinhcuoi = 1, chiso;
    for (i = k; i >= 1; i--)
    { // 1 4 5
        if (HT[i] != n - k + i)
        {
            chiso = i;
            cauhinhcuoi = 0;
            break;
        }
    }
    if (cauhinhcuoi == 1)
        return 1;
    for (i = 1; i <= chiso - 1; i++)
        TT[i] = HT[i];
    TT[chiso] = HT[chiso] + 1;
    for (i = chiso + 1; i <= n; i++) // 1 4 5 // 2 3 4
        TT[i] = TT[chiso] + i - chiso;
    return 0;
}

int main ()
{
    int i, k, n, cauhinhcuoi = 0, HT[20], TT[20];
    scanf("%d %d", &k, &n);
    for (i = 1; i <= k; i++)
        HT[i] = i;
    do {
        for (i = 1; i <= k; i++)
            printf("%d ", HT[i]);
        printf("\n");
        cauhinhcuoi = SinhTH(n,k,HT,TT);
        for (i = 1; i <= k; i++)
            HT[i] = TT[i];
    } while (cauhinhcuoi == 0);
}