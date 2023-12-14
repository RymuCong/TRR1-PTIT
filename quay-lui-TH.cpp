/*
Quay lui liệt kê các tổ hợp chập k của n phần từ: 1, 2, ..., n
Nhập k, n từ bàn phím.

Test case mẫu:

case=1

input=

3 5

output=

1 2 3

1 2 4

1 2 5

1 3 4

1 3 5

1 4 5

2 3 4

2 3 5

2 4 5

3 4 5


*/
#include<stdio.h>
void Back_Track(int i, int X[], int k, int n){
    int j;
    for(j=X[i-1]+1; j<=n-k+i; j++){
        X[i]=j;
        if(i==k){
            int p;
            for(p=1; p<=k; p++) printf("%d ", X[p]);
            printf("\n");
        }
        else
            Back_Track(i+1, X, k, n);
    }
}
int main(){
    int k, n, i, X[20];
    scanf("%d%d", &k, &n);
    X[0]=0;
    Back_Track(1, X, k, n);
}