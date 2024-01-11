/*
Chuỗi ký tự X = (X1, X2, . . ., Xn) được gọi là chuỗi ký tự AB nếu x; = ‘A’ hoặc x = ‘B’.
Chuỗi X được gọi là chuỗi AB bậc k nếu X tồn tại duy nhất một dãy k kí tự A liên tiếp.
Hãy liệt kê tất cả các chuỗi AB bậc k.

Nhập m, n từ bàn phím. Ví dụ với m=4, n=6 ta có output:

B  B  A  A  A  A

B  A  A  A  A  B

A  B  A  A  A  A

A  A  A  A  B  B

A  A  A  A  B  A
*/

#include <iostream>
using namespace std;

int a[100], m, n, ok = 1;

void in()
{
    for (int i = 1; i <= n; i++)
        cout << (char)(a[i]+65) << " ";
    cout << endl;
}

void sinhNP ()
{
    int i = n;
    while (i > 0 && a[i] == 1) // a[i] == 'B'
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
        if (a[i] == 0)
        {
            dem++;
            if (dem > m)
                return 0;
        }
        else
        {
            if (dem == m)
                return 1;
            dem = 0;
        }
    }
    return dem == m;
}

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        //a[i] = (int)'A';
        a[i] = 0;
    while (ok)
    {
        if (check())
            in();
        sinhNP();
    }
}
