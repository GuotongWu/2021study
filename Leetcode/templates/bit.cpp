#include<iostream>
using namespace std;

int lowbit(int x){
    // 返回一个二进制数，最高一位为1，为x的最后一位1
    return x & (-x);
}

void print_bit(int x){
    for(int i=10; i>=0; --i)
        cout<<(x>>i&1);
    cout<<endl;
}

int main(){
    print_bit(100);
    cout<<lowbit(100)<<endl;
    print_bit(lowbit(100));
    return 0;
}