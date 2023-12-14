/*
Quay lui có điều kiện liệt kê các hoán vị của n phần từ: 1, 2, ..., n

Nhập n từ bàn phím.

Test case mẫu:

Case=1

input =

2

output = 

1 2

2 1
*/

#include<stdio.h>
void Back_Track(int i, int X[], int unused[], int n){
    int j, q;
    for(j=1; j<=n; j++){
        if(unused[j]==1){
            X[i]=j;
            unused[j]=0;
            if(i==n){
                for(q=1; q<=n; q++) printf("%d ", X[q]);
                printf("\n");
            }
            else
                Back_Track(i+1, X, unused, n);
            unused[j]=1;
        }
    }
}
int main(){
    int n, X[20], unused[20], k;
    scanf("%d", &n);
    for(k=1; k<=n; k++) unused[k]=1;
    Back_Track(1, X, unused, n);
}