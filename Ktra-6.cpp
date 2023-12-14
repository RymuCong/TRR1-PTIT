/*
Liệt kê 5 tổ hợp tiếp theo (mỗi tổ hợp trên 1 dòng, 2 phần tử liên tiếp của 1 tổ hợp cách nhau 1 khoản trắng) của một tổ hợp chập k phần tử của n phần tử 1, 2, . . ., n.

Đọc từ bàn phím theo thứ tự:

k, n, tiếp theo là k phần tử của một tổ hợp bất kỳ.
*/
#include <iostream>
using namespace std;

void in_to_hop(int a[], int k) {
    for (int i = 1; i <= k; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool sinh_to_hop_tiep_theo(int a[], int k, int n) {
    int i = k ;
    while (i >= 0 && a[i] == n - k + i) {
        --i;
    }
    if (i > 0) {
        ++a[i];
        for (int j = i + 1; j <= k; ++j) {
            a[j] = a[j - 1] + 1;
        }
        return true;
    }
    return false;
}

int main() {
    int k, n;
    cin >> k >> n;
    int a[200];
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 5; ++i) {
        if (sinh_to_hop_tiep_theo(a, k, n)) {
            in_to_hop(a, k);
        } else {
            break;
        }
    }
    return 0;
}
