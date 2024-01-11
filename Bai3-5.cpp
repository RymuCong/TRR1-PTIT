/*
Bài 3.5. Liệt kê tất cả các xâu nhị phân độ dài n thỏa mãn điều kiện mỗi xâu có duy nhất 1 dãy k bít 1 liên tiếp; k, n nhập từ bàn phím

Nhập k, n từ bàn phím.

Ví dụ với k=3, n=5 ta có output như sau:

0 0 1 1 1

0 1 1 1 0

1 0 1 1 1

1 1 1 0 0

1 1 1 0 1
*/

#include <iostream>
using namespace std;

int a[100], k, n, ok = 1;

void in()
{
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void sinhNP ()
{
    int i = n;
    while (i > 0 && a[i] == 1)
        i--;
    if (i == 0)
        ok = 0;
    for (int j = i; j <= n; j++)
        a[j] = 1 - a[i];
}

int check ()
{
    int dem = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
        {
            dem++;
            if (dem > k)
                return 0;
        }
        else
        {
            if (dem == k)
                return 1;
            dem = 0;
        }
    }
    return dem == k;
}

int main()
{
    cin >> k >> n;
    for (int i = 1; i <= n; i++)
        a[i] = 0;
    while (ok)
    {
        if (check())
            in();
        sinhNP();
    }
}
