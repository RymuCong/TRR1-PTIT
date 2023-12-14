/* 
Bài 3.3. Liệt kê tất cả các xâu nhị phân độ dài n thỏa mãn điều kiện mỗi xâu có duy nhất 1 dãy k bít 1 liên tiếp; k, n nhập từ bàn phím

Nhập k, n từ bàn phím.

Ví dụ với k=3, n=5 ta có output như sau:

0 0 1 1 1

0 1 1 1 0

1 0 1 1 1

1 1 1 0 0

1 1 1 0 1
*/

#include <iostream>
#include <stdbool.h>
#include <string>
using namespace std;
bool check(string s,string p1,int m,string p2,int k)
{
    int d=0;
    string x=s;
    while(s.find(p1)<=s.size() && s[s.find(p1)+m]!='1')
    {
        d++;
        if(d>1) return false;
        s.erase(s.find(p1),m);
    }
    if(d==0) return false;
    while(x.find(p2)< x.size()&&x[x.find(p2)+k]!='0')
    {
        d++;
        if(d>2) return false;
        x.erase(x.find(p2),k);
    }
    if(d==2) return true;
    else return false;
}
int main()
{
    string s,p;
    int n,k,m;
    cin>>k>>m>>n;
    for(int i=0;i<m;i++)
    {
        s+="1";
        p+="1";
    }
    for(int i=0;i<k;i++)
    {
        s="0"+s;
        p+="0";
    }
    int d1=0,d2=0;
    for(int i=0;i<n-m-k;i++)
    {
        s+="0";
        d1++;
        if(d2%2==0)
        {
            if(d1<m) p+="1";
            else{
                p+="0";
                d2++;
                d1=1;
            }
        }
    }
    string h1,h2;
    for(int i=0;i<m;i++) h1+="1";
    for(int i=0;i<k;i++) h2+="0";
    while(true){
        if(check(s,h1,m,h2,k)==true){
            for(int i=0;i<n;i++)
            cout<<s[i]<<" ";
            cout<<endl;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0')
            {
                s[i]='1';
                for(int j=i+1;j<n;j++)
                s[j]='0';
                break;
            }
        }
        if(s==p) break;
    }
    for(int i=0;i<n;i++) cout<<s[i]<<" ";
    cout<<endl;
    return 0;
}
