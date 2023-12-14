/*
Chuỗi ký tự X = (X1, X2, . . ., Xn) được gọi là chuỗi ký tự AB nếu x; = ‘A’ hoặc x = ‘B’. 
Chuỗi X được gọi là chuỗi AB bậc k nếu X tồn tại duy nhất một dãy k kí tự A liên tiếp.
Hãy liệt kê tất cả các chuỗi AB bậc k.

Nhập m, n từ bàn phím. Ví dụ với m=4, n=6 ta có output:

B  B  A  A  A  A

B  A  A  A  A  B

A  B  A  A  A  A

A  A  A  A  B  B

A  A  A  A  B  A
*/
#include <stdio.h>
#include <stdlib.h>
int is_AB_degree_k(char*s,int n,int k){
    int count=0;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='A'){
            count++;
        }
        else{
            if(count == k){
                flag++;
            }
            count=0;
        }
    }
    if(count == k){
        flag++;
    }
    return flag==1;
}
void generate_AB_degree_k(int n,int k){
    char*s=(char*)malloc((n+1)*sizeof(char));
    for(int i=0;i<n;i++){
        s[i]='B';
    }
    s[n]='\0';
    int stop=0;
    while(!stop){
        if(is_AB_degree_k(s,n,k)){
            for(int i=0;i<n;i++)
            {
                printf ("%c ",s[i]);
            }
            printf("\n");
        }
        int i=n-1;
        while(i>=0&&s[i]=='A'){
            s[i]='B';
            i--;
        }
        if(i>=0){
            s[i]='A';
        }
        else stop=1;
    }
    free(s);
}
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    generate_AB_degree_k(n,m);
}