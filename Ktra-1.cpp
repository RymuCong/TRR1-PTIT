/*
Cho biểu thức logic: (p -> q) ^ (r <=> s) v (-p)

Viết chương trình xác định giá trị chân lý (ứng với mỗi bộ giá trị chân lý của các mệnh đề thành phần p, q, r, s) của biểu thức logic đã cho.

Thứ tự của các bộ giá trị chân lý của các mệnh đề thành phần cho như sau:

p q r s

F F F F

F F F T

F F T F

F F T T

F T F F

F T F T

F T T F

F T T T

T F F F

T F F T

T F T F

T F T T

T T F F

T T F T

T T T F

T T T T

Chú ý: Trước khi evaluate, phải copy code ra Dev-C thử trước. Nếu không thử, evaluate ngay dẫn đến treo tiến trình thì sẽ không thể làm bài tiếp và nhận 0 điểm.

Input: không

Output: mỗi dòng in giá trị chân lý (T hoặc F) của biểu thức đã cho ứng với 1 bộ giá trị chân lý của các mệnh đề thành phần (theo thứ tự đã cho ở trên).
*/
#include <iostream>
using namespace std;

int logic (int p, int q, int r, int s)
{
	return ((not p or q) and (r == s)) or not p;
}

int sinhNP (int n, int HT[20], int TT[20])
{
	int cauhinhcuoi = 1, i, k;
	for (i = 4; i >= 1; i--)
	{
		if (HT[i] == 0)
		{
			k = i;
			cauhinhcuoi = 0;
			break;
		}
	}
	if (cauhinhcuoi == 1)
		return 1;
	for (i = 1; i <= k - 1; i++)
		TT[i] = HT[i];
	for (i = k; i <= 4; i++)
		TT[i] = 1 - HT[i];
	return 0;
}

int main ()
{
	int i, cauhinhcuoi = 0, HT[20], TT[20];
	for (i = 1; i <= 4; i++)
		HT[i] = 0;
	do
	{
		if (logic(HT[1], HT[2], HT[3], HT[4]))
			cout << "T\n";
		else
			cout << "F\n";
		cauhinhcuoi = sinhNP(4,HT,TT);
		for (i = 1; i <= 4; i++)
			HT[i] = TT[i]; 
	} while (cauhinhcuoi == 0);
}
