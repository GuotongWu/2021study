#include<iostream>
#include<unordered_map>
#include<cstdio>
using namespace std;

int main(){
    int a[] = {1, 2, 2, 3, 5};
    int n = 5;

    unordered_map<int,int> hash;
    int res = 0;

    for(int i=0, j=0; j<n; ){
        if(hash.find(a[j]) == hash.end()) // 没有找到
            hash[a[j++]] = j;
        else{
            i = hash[a[j]] + 1;
            hash.erase(a[j]);
        }
        res = max(res, j-i+1);
    }

    cout<<res<<endl;

    return 0;
}