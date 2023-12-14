/*
Viết chương trình giải bài toán dưới đây trên máy tính sử dụng thuật toán duyệt toàn bộ:
Bài toán cái túi dạng 0 / 1 - mỗi thứ hoặc không lấy, hoặc lấy 1 (vào từ file, ra màn hình).
So loai do vat: 4
Trong luong tui: 9
Vector trong luong: 4 2 7 1
Vector gia tri su dung: 5 1 8 1
Ket qua toi uu: 9.0
Phuong an toi uu: 0 0 1 1
*/
#include <iostream>
using namespace std;

int x[100],gt[100], m[100], solve[100];
int tl_max, gt_max;

int check ()
{
    int tl = 0;
    for (int i = 0; i <= 3; i++)
    {
        tl += x[i] * m[i];
    }
    if (tl > tl_max)
        return 0;
    return 1;
}

void update ()
{
    int tong_gt = 0;
    for (int i = 0; i <= 3; i++)
    {
        tong_gt += x[i] * gt[i];
    }
    if (tong_gt > gt_max)
    {
        gt_max = tong_gt;
        for (int i = 0; i <= 3; i++)
            solve[i] = x[i];
    }
}

void duyet_toan_bo (int i)
{
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (i == 3)
        {
            if(check())
                update();
        }
        else
        {
            duyet_toan_bo(i+1);
        }
    }
}

int main ()
{
    int n;
    cin >> n >> tl_max;
    for (int i = 0; i < n; i++)
        cin >> m[i];
    for (int i = 0; i < n; i++)
        cin >> gt[i];
    duyet_toan_bo(0);
    printf("%.1f\n",(float)gt_max);
    for (int i = 0; i < n; i++)
        cout << solve[i] << " ";
    cout << endl;
    return 0;
}