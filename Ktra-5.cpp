/*
1. Xây dựng hệ thức truy hồi tính số xâu nhị phân độ dài n, không có 2 số 1 liên tiếp (ký hiệu là an). Đọc n từ bàn phím, tính và in trên dòng đầu tiên an.

2. Bắt đầu từ dòng 2, mỗi dòng in 1 xâu nhị phân độ dài n (2 bít liền nhau cách nhau 1 khoảng trắng) thỏa mãn điều kiện ở ý 1. Thứ tự in theo thứ tự từ điển.

3. Đếm số các xâu in được ở ý 2, sau đó in ở dòng cuối cùng.

(chú ý là bài làm đúng thì số ở dòng 1 và dòng cuối cùng phải bằng nhau)
*/
#include <iostream>
using namespace std;

int demNP (int n)
{
    int a = 1, b = 1;
    for (int i = 2; i <= n; i++)
    {
        int tmp = a;
        a = a + b;
        b = tmp;
    }
    return a+b;
}

void inNP (int n, string s, int NPcuoi)
{
    if (n == 0)
    {
        for (int i = 0; i < s.length(); i++)
            cout << s[i] << " ";
        cout << endl;
        return;
    }
    inNP(n-1,s+"0",0);
    if (NPcuoi == 0)
        inNP(n-1,s+"1",1);
}

int main ()
{
    int n;
    cin >> n;
    int dem = demNP(n);
    cout << dem << endl;
    inNP(n,"",0);
    cout << dem << endl;
    return 0;
}
