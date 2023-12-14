/*
Sử dụng phương pháp duyệt toàn bộ và thuật toán sinh xâu nhị phân giải bài toán cái túi dạng 0/1 được cho dưới dạng:

- Hàm mục tiêu: 10x1 + 5x2 + 3x3 + 6x4 -> max

- Ràng buộc: 5x1 + 3x2 + 2x3 + 4x4 <= 8

với x1, x2, x3, x4 = 0 hoặc 1.

Input: không

Output: dòng thứ nhất là giá trị tối ưu, dòng thứ 2 in nghiệm tối ưu x1 x2 x3 x4 (hai giá trị liền nhau cách nhau 1 khoảng trắng)
*/
#include <iostream>
using namespace std;

int x[4] = {0, 0, 0, 0};
int gia_tri[4] = {10, 5, 3, 6};
int trong_luong[4] = {5, 3, 2, 4};
int trong_luong_toi_da = 8;
int gia_tri_toi_uu = 0;
int nghiem_toi_uu[4];

void in_nghiem() {
    for (int i = 0; i < 4; ++i) {
        cout << nghiem_toi_uu[i] << " ";
    }
    cout << endl;
}

bool kiem_tra() {
    int tong_trong_luong = 0;
    for (int i = 0; i < 4; ++i) {
        tong_trong_luong += x[i] * trong_luong[i];
    }
    return tong_trong_luong <= trong_luong_toi_da;
}

void cap_nhat() {
    int tong_gia_tri = 0;
    for (int i = 0; i < 4; ++i) {
        tong_gia_tri += x[i] * gia_tri[i];
    }
    if (tong_gia_tri > gia_tri_toi_uu) {
        gia_tri_toi_uu = tong_gia_tri;
        for (int i = 0; i < 4; ++i) {
            nghiem_toi_uu[i] = x[i];
        }
    }
}

void duyet_toan_bo(int i) {
    for (int j = 0; j <= 1; ++j) {
        x[i] = j;
        if (i == 3) {
            if (kiem_tra()) {
                cap_nhat();
            }
        } else {
            duyet_toan_bo(i + 1);
        }
    }
}

int main() {
    duyet_toan_bo(0);
    cout << gia_tri_toi_uu << endl;
    in_nghiem();
    return 0;
}
