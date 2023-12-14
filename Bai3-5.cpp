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
bool check(string s,string p,int k)
{
    int d=0;
    while(s.find(p)<=s.size()&& s[s.find(p)+k]!='1')
    {
        d++;
        s.erase(s.find(p),k);
        if(d>1)
        return false;
    }
    if(d==1)
    return true;
    else
    return false;
}
int main()
{
    string s,p;
    int n,k;
    cin>>k>>n;
    for(int i=n-k;i<n;i++)
    {
        s+="1";
        p="1"+p;
    }
    if(k<n)
    p+="0";
    int d=0;
    for(int i=0;i<n-k;i++)
    {
        s="0"+s;
        d++;
        if(d<k)
        p+="1";
        else{
        p+="0";
        d=0;
        }
    }
    p.erase(n,1);
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
    string h;
    for(int i=0;i<k;i++)
    {
        h+="1";
    }
    while(true)
    {
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
        if(check(s,h,k)==true)
        {
            for(int i=0;i<n;i++)
            cout<<s[i]<<" ";cout<<endl;
        }
        if(s==p)
        break;
    }
}

