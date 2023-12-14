/* 
Bài 3.3. Liệt kê tất cả các xâu nhị phân độ dài n thỏa mãn điều kiện mỗi xâu có duy nhất 1 dãy k bít 1 liên tiếp; k, n nhập từ bàn phím

Nhập k, n từ bàn phím.

Ví dụ với k=3, n=5 ta có output như sau:

0 0 1 1 1

0 1 1 1 0

1 0 1 1 1

1 1 1 0 0

1 1 1 0 1
*/

#include <stdio.h>
int nextToHop(int X[], int Y[], int k, int n)
{
    int i, t, cauhinhcuoi = 1;
    for (i = k; i >= 1; i--)
        if (X[i] != n - k + i) // 1 2 3
        {
            t = i;
            cauhinhcuoi = 0;
            break;
        }
    if (cauhinhcuoi == 1)
        return 1;
    for (i = 1; i <= t - 1; i++)
        Y[i] = X[i];
    Y[t] = X[t] + 1;
    for (i = t + 1; i <= k; i++)
        Y[i] = Y[t] + (i - t);
    return 0;
}
int main()
{
    int k, n, i, X[20], Y[20], cauhinhcuoi;
    scanf("%d%d", &k, &n);
    //  Cấu hình bắt đầu
    for (i = 1; i <= k; i++)
        X[i] = i;
    do
    {
        for (i = 1; i <= k; i++)
            printf("%d ", X[i]);
        printf("\n");
        cauhinhcuoi = nextToHop(X, Y, k, n);
        for (i = 1; i <= k; i++)
            X[i] = Y[i];
    } while (cauhinhcuoi == 0);
}
