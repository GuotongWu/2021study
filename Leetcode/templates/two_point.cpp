#include<iostream>
using namespace std;
const int N = 10000;

bool check(int i, int j){
    return true;
}

int main(){
    for(int i=0,j=0; i<N; ++i){
        while(j<N && check(i,j))
            ++j;
        // 具体内容
    }
    return 0;
}