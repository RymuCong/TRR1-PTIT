/*
Viết chương trình giải bài toán dưới đây trên máy
tính sử dụng thuật toán duyệt toàn bộ:
Bài toán người du lịch (vào từ file, ra màn hình).
So thanh pho: 5
Ma tran chi phi:
0 3 14 18 15
3 0 4 22 20
17 9 0 16 4
6 2 7 0 12
9 15 11 5 0
Chi phi toi uu 22:
Hanh trinh: 1-> 2 -> 3 -> 5 -> 4 -> 1
*/

/*
Hàm Try() trong đoạn mã trên là một hàm đệ quy được sử dụng để thử tất cả các hành trình có thể từ một thành phố đến tất cả các thành phố khác.

Hàm này nhận vào một tham số i, đại diện cho vị trí hiện tại trong hành trình.

Bên trong hàm, chúng tôi duyệt qua tất cả các thành phố từ 2 đến n (vì thành phố 1 đã được chọn làm điểm xuất phát). Nếu thành phố j chưa được thăm (!visited[j]), chúng tôi thêm thành phố j vào hành trình hiện tại (x[i] = j), đánh dấu thành phố j là đã được thăm (visited[j] = true) và cập nhật chi phí hành trình hiện tại (cost += c[x[i - 1]][j]).

Nếu i bằng n, tức là chúng tôi đã thăm tất cả các thành phố, chúng tôi kiểm tra xem chi phí hành trình hiện tại cộng với chi phí từ thành phố cuối cùng trở lại thành phố xuất phát có nhỏ hơn chi phí tối thiểu hiện tại hay không (cost + c[x[n]][x[1]] < minC). Nếu có, chúng tôi cập nhật chi phí tối thiểu (minC) và hành trình tốt nhất (bestWay).

Nếu i không bằng n, chúng tôi kiểm tra xem chi phí hành trình hiện tại cộng với ước lượng chi phí tối thiểu để thăm các thành phố còn lại có nhỏ hơn chi phí tối thiểu hiện tại hay không (cost + (n - i + 1) * c[0][j] < minC). Nếu có, chúng tôi tiếp tục thử thêm thành phố vào hành trình (Try(i + 1)).

Cuối cùng, chúng tôi hoàn tác các thay đổi đã thực hiện để thử thành phố tiếp theo (visited[j] = false và cost -= c[x[i - 1]][j]).
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 20;
const int INF = 1e9; // 1 số rất lớn
int n, c[N][N], x[N], bestWay[N], minC = INF, cost = 0;
bool visited[N] = {false};

void Try(int i) {
    for (int j = 2; j <= n; j++) {
        if (!visited[j]) {
            x[i] = j;
            visited[j] = true;
            cost += c[x[i - 1]][j];
            if (i == n) {
                if (cost + c[x[n]][x[1]] < minC) {
                    minC = cost + c[x[n]][x[1]];
                    for (int i = 1; i <= n; i++) {
                        bestWay[i] = x[i];
                    }
                }
            } else if (cost + (n - i + 1) * c[0][j] < minC) {
                Try(i + 1);
            }
            visited[j] = false;
            cost -= c[x[i - 1]][j];
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
            if (c[i][j] == 0) c[i][j] = INF;
        }
    }
    x[1] = 1;
    Try(2);
    printf("%.1f\n",(float)minC);
    for (int i = 1; i <= n; i++) {
        cout << bestWay[i] << " ";
    }
    cout << "1";
    return 0;
}
