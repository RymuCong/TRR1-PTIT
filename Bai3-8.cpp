/*
Bài 3.6. Liệt kê các dãy con

Cho dãy số A = (a1, a2), . . ., an) gồm n số tự nhiên khác nhau và số tự nhiên k. 
Hãy liệt kê tất cả các dãy con của dãy số A sao cho tổng các phần tử của dãy con đó đúng bằng k.

Nhập k, n và dãy số từ bàn phím.

Ví dụ với m=14, n=8 và dãy số 11 12 13 14 15 0 1 2

ta có output:

14

14  0

13  1

13  0  1

12  2

12  0  2

11  1  2

11  0  1  2
*/

#include<iostream>
#include <vector>
using namespace std;
void check(int a[],int n,int k,vector<int> v,int i){
    if(i==n){
        int tong=0;
        for(int j=0;j<v.size();j++)
        {
            tong=tong+v[j];
        }
        if(tong==k)
        {
            for(int j=0;j<v.size();j++){
                cout<<v[j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    check(a,n,k,v,i+1);
    v.push_back(a[i]);
    check(a,n,k,v,i+1);
}
int main()
{
    int n,k;
    cin>>k>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int >v;
    check(a,n,k,v,0);
}