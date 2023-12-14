/*
Bài 3.4. Sinh tất cả các hoán vị của n phần từ 1, 2, ..., n
Input format:

- Đọc n từ bàn phím

Output format:

- In ra tất cả các hoán vị của n phần từ 1 .. n, các phần tử của 1 hoán vị cách nhau một vài khoảng trống

- Mỗi hoán vị trên 1 dòng

Ví dụ: các hoán vị của 3 phần tử 1, 2, 3 gồm:

1 2 3

1 3 2

2 1 3

2 3 1

3 1 2

3 2 1
*/

#include <stdio.h>
int nextPermutation(int a[], int b[], int n)
{
    int i, j, k, cauhinhcuoi = 1;
    for (i = n; i >= 2; i--)
        if (a[i - 1] < a[i])
        {
            cauhinhcuoi = 0;
            j = i - 1;
            break;
        }
    if (cauhinhcuoi == 1)
        return 1;
    for (i = n; i > j; i--)
        if (a[i] > a[j])
        {
            int tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
            break;
        }
    int left = j + 1, right = n;
    while (left < right)
    {
        int tmp = a[left];
        a[left] = a[right];
        a[right] = tmp;
        left++;
        right--;
    }
    for (i = 1; i <= n; i++)
        b[i] = a[i];
    return 0;
}
int main()
{
    int n, cauhinhcuoi = 0, i, a[20], b[20];
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        a[i] = i;
    do
    {
        for (i = 1; i <= n; i++)
            printf("%d ", a[i]);
        printf("\n");
        cauhinhcuoi = nextPermutation(a, b, n);
        for (i = 1; i <= n; i++)
            a[i] = b[i];
    } while (cauhinhcuoi == 0);
}