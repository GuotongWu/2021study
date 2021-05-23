#include<iostream>
const int N = 1000;
int m,n;
int a[N][N],s[N][N];

int main(){
    scanf("%d%d", &m, &n);
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j)
            scanf("%d", &a[i][j]);
    
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j)
            s[i][j] = s[i-1][j] + s[i][j-1] + a[i][j] - s[i-1][j-1]; // 前缀和

    // area = s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1-1][y1-1]

    for(int i=0; i<=m; ++i){
        for(int j=0; j<=n; ++j)
            printf("%d ", s[i][j]);
        printf("\n");
    }

    return 0;
}