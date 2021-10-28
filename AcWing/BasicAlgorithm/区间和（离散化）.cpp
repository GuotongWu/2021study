#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 3e5+10;

typedef pair<int,int> PII;

int n, m;
int s[N], a[N];

vector<PII> add, query;
vector<int> alls;

int find(int n){
    int l = 0, r = alls.size()-1;
    while(l < r){
        int mid = (l+r)>>1;
        if(alls[mid] >= n)
            r = mid;
        else
            l = mid+1;
    }
    return r+1;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; ++i){
        int x, c;
        scanf("%d%d", &x, &c);
        add.push_back({x,c});
        alls.push_back(x);
    }
    for(int i=0; i<m; ++i){
        int l, r;
        scanf("%d%d", &l, &r);
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    
    // 去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    
    for(auto item: add){
        int x = find(item.first);
        a[x] += item.second;
    }
    
    for(int i=1; i<=alls.size(); ++i)
        s[i] = s[i-1] + a[i];
    
    for(auto item:query){
        int l = find(item.first), r = find(item.second);
        cout<<s[r]-s[l-1]<<endl;
    }
    
    return 0;
}