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

int n, tl_max, res = 0;
int tl[100], gt[100], x[100], x_best[100];

void update() {
    int sum_tl = 0, sum_gt = 0;
    for (int i = 0; i < n; ++i) {
        if (x[i]) {
            sum_tl += tl[i];
            sum_gt += gt[i];
        }
    }
    if (sum_tl <= tl_max && sum_gt > res) {
        res = sum_gt;
        for (int i = 0; i < n; ++i) {
            x_best[i] = x[i];
        }
    }
}

void Try(int i) {
    for (int j = 0; j <= 1; ++j) {
        x[i] = j;
        if (i == n - 1) update();
        else Try(i + 1);
    }
}

int main() {
    cin >> n >> tl_max;
    for (int i = 0; i < n; ++i)
        cin >> tl[i];
    for (int i = 0; i < n; ++i)
        cin >> gt[i];
    Try(0);
    printf("%.1f\n",(float)res);
    for (int i = 0; i < n; ++i) {
        cout << x_best[i] << " ";
    }
    return 0;
}