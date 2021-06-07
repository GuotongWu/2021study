#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

void add(int & res1, int & res2, int a, int b){
    res1 = res1*b + a*res2;
    res2 *= b;
}

int gcd(int res1, int res2){
    if(res2 > res1)
        return gcd(res2, res1);
    while(res2){
        int temp = res1;
        res1 = res2;
        res2 = temp % res2;
    }
    return res1;
}

void reduction(int res1, int res2){
    if(!res1){
        cout<<0;
        return;
    }
    if(abs(res1) >= abs(res2))
        cout<<res1/res2<<" ";
    if(res1 % res2){
        int a = (res1%res2) / gcd(res1%res2, res2);
        int b = res2 / gcd(res1%res2, res2);
        if(b < 0)
            cout<<-1*a<<"/"<<-1*b;
        else
            cout<<a<<"/"<<b;
    }
}

int main(){
    int res1 = -2, res2 = 3;
    add(res1, res2, 1, 3);
    // cout<<res1<<" "<<res2<<endl;
    reduction(res1, res2);
}