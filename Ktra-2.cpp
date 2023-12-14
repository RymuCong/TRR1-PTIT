/*
1. In trên dòng 1 số các số nguyên có 5 chữ số, không chứa các chữ số 2, 3, 4, 6, 7 và không có chữ số nào giống nhau.

2. In trên dòng 2 tất cả các số thỏa mãn yêu cầu ở ý 1 (in theo thứ tự giá trị tăng dần), 2 số liền nhau cách nhau 1 khoảng trắng.

3. Đếm số các số in được trên dòng 2 sau đó in ở dòng 3.

(chú ý là bài làm đúng thì số ở dòng 1 và dòng 3 phải bằng nhau)
*/
#include <iostream>
#include <string>
using namespace std;

bool check_number(int n) {
    string chuoi_n = to_string(n);
    string tu_cam = "23467";
    for (int i = 0; i < chuoi_n.length(); i++) {
        if (tu_cam.find(chuoi_n[i]) != string::npos) {
            return false;
        }
        for (int j = i + 1; j < chuoi_n.length(); j++) {
            if (chuoi_n[i] == chuoi_n[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int a[90000], dem = 0, dem2 = 0;
    for (int i = 10000; i < 100000; i++) {
        if (check_number(i)) {
            a[dem] = i;
            dem++;
        }
    }

	cout << dem << endl;

    for (int i = 0; i < dem; i++) {
        cout << a[i] << " ";
        dem2++;
    }
    cout << endl;

    cout << dem2 << endl;

    return 0;
}
