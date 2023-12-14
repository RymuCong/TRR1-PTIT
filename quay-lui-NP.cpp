/*
Quay lui liệt kê xau nhị phân
Nhập n từ bàn phím.

Test case mẫu:

case=1

input=

3

output=

000

001

010

011

100

101

110

111
*/

#include <stdio.h>
void Back_Track(int i, int X[], int n)
{
    int j, k;
    for (j = 0; j <= 1; j++)
    {
        X[i] = j;
        if (i == n)
        {
            for (k = 1; k <= n; k++)
                printf("%d ", X[k]);
            printf("\n");
        }
        else
            Back_Track(i + 1, X, n);
    }
    return;
}
int main()
{
    int n, X[20];
    scanf("%d", &n);
    Back_Track(1, X, n);
    return 0;
}
