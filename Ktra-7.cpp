/*
Liệt kê 4 hoán vị tiếp theo (mỗi hoán vị trên 1 dòng, 2 phần tử liên tiếp của 1 hoán vị cách nhau 1 khoảng trắng) của một hoán vị của n phần tử 1, 2, . . ., n.

Đọc từ bàn phím theo thứ tự:

n, tiếp theo là n phần tử của một hoán vị bất kỳ.
*/
#include <iostream>
using namespace std;

void in_hoan_vi(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool sinh_hoan_vi_tiep_theo(int a[], int n) {
    int i = n - 2; // 1 3 2 4
    while (i >= 0 && a[i] > a[i + 1]) {
        --i;
    }
    if (i >= 0) {
        int k = n - 1;
        while (a[k] < a[i]) {
            --k;
        }
        swap(a[i], a[k]);
        int l = i + 1, r = n - 1;
        while (l < r) {
            swap(a[l], a[r]);
            ++l;
            --r;
        }
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int a[200];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 4; ++i) {
        if (sinh_hoan_vi_tiep_theo(a, n)) {
            in_hoan_vi(a, n);
        } else {
            break;
        }
    }
    return 0;
}
