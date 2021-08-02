#include<iostream>
using namespace std;

const int N = 100010;
int h[N], sz;
int n, m;

void down(int u){
    int t = u;
    if(2*u<=sz && h[2*u]<h[t])
        t = 2*u;
    if(2*u+1<=sz && h[2*u+1]<h[t])
        t = 2*u+1;
    if(t != u){
        swap(h[t], h[u]);
        down(t);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i)
        scanf("%d", &h[i]);
    sz = n;
    
    for(int i=n/2; i; --i)
        down(i);
        
    for(int i=0; i<m; ++i){
        printf("%d ", h[1]);
        // 删除结点
        h[1] = h[sz];
        --sz;
        down(1);
    }
    return 0;
}