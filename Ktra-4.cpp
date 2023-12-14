/*
Trong tập các số từ 4000 đến 5000:

1. Áp dụng nguyên lý bù trừ để tính toán và in trên dòng 1 số các số không chia hết cho bất kỳ số nào trong 3 số 2, 5, 15.

2. Bắt đầu từ dòng 2, mỗi dòng in 10 số (2 số liền nhau cách nhau 1 khoảng trắng) thỏa mãn điều kiện ở ý 1.

3. Đếm số các số in được ở ý 2, sau đó in ở dòng cuối cùng.

(chú ý là bài làm đúng thì số ở dòng 1 và dòng cuối cùng phải bằng nhau)
*/
#include <iostream>
using namespace std;

void dem_so() {
    int dem = 0;
    int dem_dong = 0;
    for (int i = 4000; i <= 5000; i++) {
        if (i % 2 != 0 && i % 5 != 0 && i % 15 != 0) {
            cout << i << ' ';
            dem++;
            dem_dong++;
            if (dem_dong == 10) {
                cout << endl;
                dem_dong = 0;
            }
        }
    }
    if (dem_dong != 0) {
        cout << endl;
    }
    cout << dem << endl;
}

int main() {
	// nhung so k chia het tu 1 -> 5000 roi tru di nhung so k chia het tu 1 -> 4000
	cout << (5000 - (int(5000/2) + int(5000/5) + int(5000/15) - int(5000/10) - int(5000/30) - int(5000/15) + int(5000/30)))
	- (4000 - (int(4000/2) + int(4000/5) + int(4000/15) - int(4000/10) - int(4000/30) - int(4000/15) + int(4000/30))) << endl;
    dem_so();
    return 0;
}

