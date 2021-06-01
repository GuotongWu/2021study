#include<iostream>
using namespace std;

const int N = 1e5+10;
int p[N], s[N];
int n,m;

int find(int x){
    if(p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; ++i){
        p[i] = i;
        s[i] = 1;
    }
        
    while(m--){
        string op;
        int x, y;
        cin>>op;
        if(op == "C"){
            cin>>x>>y;
            p[find(x)] = find(y);
            s[find(y)] += s[find(x)];
        }
        else if(op == "Q1"){
            cin>>x>>y;
            if(find(x) == find(y))
                printf("Yes\n");
            else
                printf("No\n");
        }
        else{
            cin>>x;
            printf("%d\n", s[find(x)]);
        }
    }
    return 0;
}