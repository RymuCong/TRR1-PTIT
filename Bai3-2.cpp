/* 
Liệt kê tất cả các phương án đi từ vị trí (0,0) đến vị trí (n,m) trên hình chữ nhật n x m hình vuông đơn vị
Due date: Friday, 20 October 2023, 9:03 AM

Gọi bước ngang là N, bước đứng là D.

Nhập m, n từ bàn phím, ví dụ:

m, n = 1 2

Kết quả:

N N D

N D N

D N N



m, n = 1 1

Kết quả:

N D

D N
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    string s,p;
    for(int i=0;i<m;i++)
    {
        s+="H";
        cout<<"H ";
        p = "H" + p;
    }
    for(int i=0;i<n;i++)
    {
        s+="V";
        cout<<"V ";
        p="V"+p;
    }cout<<endl;
    int k=n+m;
    while(true)
    {
        int d=0;
        for(int i=k;i>=0;i--)
        {
            if(s[i]=='V')
            d++;
            else if(s[i]=='H'&&d>0)
            {
                s[i]='V';
                for(int j=i+1;j<=k;j++)
                s[j]='H';
                for(int j=k-d+1;j<k;j++)
                s[j]='V';
                break;
            }
        }
        for(int i=0;i<k;i++) cout<<s[i]<<" ";cout<<endl;
            if(s==p)
            break;
            
    }
}
