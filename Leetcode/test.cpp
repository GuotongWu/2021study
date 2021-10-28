#include<iostream>
#include<unordered_map>
using namespace std;

int g[7][7] = {
    1, 5, -1, -1, -1, -1, -1,
    0, 2, 6, -1, -1, -1, -1,
    1, 3, 6, -1, -1, -1, -1,
    2, 4, -1, -1, -1, -1, -1,
    3, 5, 6, -1, -1, -1, -1,
    0, 4, 6, -1, -1, -1, -1,
    1, 2, 4, 5, -1, -1, -1,
};
string s = "0000000";
unordered_map<string, int> h;

void dfs(int last){
    for(int i=0; g[last][i]!=-1; ++i){
        string temp = s;
        s[g[last][i]] = '1';
        if(h.find(s) == h.end()){
            h[s] = 1;
            cout<<s<<endl;
            dfs(g[last][i]);
        }
        s = temp;
    }
}

int main(){
    for(int i=0; i<7; ++i){
        s[i] = '1';
        h[s] = 1;
        cout<<s<<endl;
        dfs(i);
        s[i] = '0';
    }
    cout<<h.size()<<endl;
    return 0;
}