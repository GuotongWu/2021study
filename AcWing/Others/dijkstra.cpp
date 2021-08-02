#include<iostream>
#include<cstring>
using namespace std;

const int N = 510;
int g[N][N];
int visited[N];
int res[N];
int n,m;

int dijkstra(){
    memset(res, 0x3f, sizeof(res));
    res[1] = 0;
    
    for(int i=0; i<n; ++i){
        int t = -1;
        for(int j=1; j<=n; ++j)
            if(!visited[j] && (t==-1 || res[j]<res[t]))
                t = j;
        
        visited[t] = 1;
                
        for(int j=1; j<=n; ++j)
            res[j] = min(res[j], res[t]+g[t][j]);
    }
    
    return res[n]==0x3f3f3f3f? -1: res[n];
}

int main(){
    memset(g, 0x3f, sizeof(g));
    
    cin>>n>>m;
    while(m--){
        int x, y, z;
        cin>>x>>y>>z;
        g[x][y] = min(g[x][y], z);
    }
    cout<<dijkstra();
    return 0;
}