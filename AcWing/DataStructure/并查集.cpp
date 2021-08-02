/* 并查集 */
/* 
    主要操作是合并两个数所在集合，询问两个数是否在同一个集合之中
 */
#include<iostream>
using namespace std;

const int N = 1e5+10;
int fa[N];

void init(int n){
    for(int i=0; i<n; ++i)
        fa[i] = i;
}

int find(inx x){
    if(fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int x, int y){
    fa[find(x)] = find(y);
}


bool query(int x, int y){
    return find(x) == find(y);
}

int main(){
    cin>>n;
    init(n);
    return 0;
}
