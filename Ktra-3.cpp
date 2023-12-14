/*
Phương trình: x1 + x2 + x3 + x4 + x5 + x6 = 15

có bao nhiêu nhiệm nguyên không âm thỏa mãn điều kiện: 4 < x1 < 7 và 5 < x2 < 9.

1. In trên dòng 1 số các nghiệm tính toán được sử dụng nguyên lý đếm Tổ hợp lặp.

2. Bắt đầu từ dòng 2, mỗi dòng in một nghiệm là các giá trị từ x1 đến x6 (chỉ in giá trị), 2 giá trị liền nhau cách nhau 1 khoảng trắng. Thứ tự in các bộ nghiệm là theo thứ tự từ điển nếu xem mỗi nghiệm là chuỗi các chữ số đứng liền nhau (hoặc theo giá trị tăng dần nếu xem x1x2x3x4x5x6 là 1 số có 6 chữ số).

Ví dụ in 2 nghiệm bất kỳ trên 2 dòng như sau:

. . .

5 6 4 0 0 0

. . .

6 7 2 0 0 0

. . .

3. Đếm số các nghiệm tìm được ở ý 2, sau đó in ở dòng cuối cùng.

(chú ý là bài làm đúng thì số ở dòng 1 và dòng cuối cùng phải bằng nhau)
*/
#include <iostream>
using namespace std;

void PTNN() {
    int dem = 0;
    for (int x1 = 5; x1 < 7; ++x1) {
        for (int x2 = 6; x2 < 9; ++x2) {
            for (int x3 = 0; x3 <= 15; ++x3) {
                for (int x4 = 0; x4 <= 15 - x3; ++x4) {
                    for (int x5 = 0; x5 <= 15 - x3 - x4; ++x5) {
                        int x6 = 15 - x1 - x2 - x3 - x4 - x5;
                        if (x6 >= 0) {
                            cout << x1 << ' ' << x2 << ' ' << x3 << ' ' << x4 << ' ' << x5 << ' ' << x6 << endl;
                            dem++;
                        }
                    }
                }
            }
        }
    }
    cout << dem << endl;
}

int giaiThua(int n) 
{
	int giai_thua = 1;
	for (int i = 1; i <= n; i++) 
		giai_thua *= i;
	return giai_thua;
}

int toHop(int n, int k) 
{
	return giaiThua(n) / (giaiThua(k) * giaiThua(n - k));
}

int main() {
	cout << (toHop(15+5-5-6,5) - toHop(15+5-7-6,5) - toHop(15+5-5-9,5) + 0) << endl;
    PTNN();
    return 0;
}
