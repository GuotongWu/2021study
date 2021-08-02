#include<iostream>
#include<vector>
using namespace std;

string p, s;

int main(){
    p = "aaa";
    s = "caaabbb";

    // next数组
    vector<int> next(p.length());
    next[0] = -1;
    for(int i=1; i<p.length(); ++i){
        int j = next[i-1];
        while(j>=0 && p[i]!=p[j+1])
            j = next[j];
        if(p[i] == p[j+1])
            next[i] = j+1;
        else
            next[i] = -1;
    }

    //kmp匹配
    int i=0, j=0;
    while(i<p.length() && j<s.length()){
        if(p[i] == s[j]){
            ++i; ++j;
        }
        else if(i > 0)
            i = next[i-1] + 1;
        else
            ++j;
    }

    // 判断
    i==p.length()? cout<<"Yes"<<endl: cout<<"No"<<endl;
    return 0;
}