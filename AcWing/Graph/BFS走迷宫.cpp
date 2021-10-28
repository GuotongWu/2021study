#include<iostream>
#include<queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 110;
int g[N][N], state[N][N];
int n,m;
queue<PII> q;

void bfs(){
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            state[i][j] = -1;
    
    q.push({1,1});
    state[1][1] = 0;
    
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        
        for(int i=0; i<4; ++i){
            int nex = x + dx[i], ney = y + dy[i];
            if(nex<=n && nex>=1 && ney<=m && ney>=1 && !g[nex][ney] && state[nex][ney]==-1){
                state[nex][ney] = state[x][y] + 1;
                if(nex==n && ney==m)
                    return;
                q.push({nex, ney});
            }
        }
        
        q.pop();
    }
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            scanf("%d", &g[i][j]);
    bfs();
    cout<<state[n][m]<<endl;
    return 0;
}