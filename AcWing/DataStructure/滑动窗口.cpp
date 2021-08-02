#include<iostream>
#include<deque>
#include<vector>
using namespace std;

const int N = 1e6+10;
int a[N];

typedef pair<int, int> PII;

deque<PII> qmax, qmin;
vector<int> rmax, rmin;

int main(){
    int n,k;
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; ++i)
        scanf("%d", &a[i]);
    
    qmax.push({0,a[0]});
    qmin.push({0,a[0]});

    for(int i=1; i<n; ++i){
        if(i >= k){
            rmax.push_back(qmax.front().second);
            rmin.push_back(qmin.front().second);
        }

        while(!qmax.empty() && a[i]>=qmax.back().second)
            qmax.pop_back();
        qmax.push_back({i,a[i]});
        while(!qmin.empty() && a[i]<=qmin.back().second)
            qmin.pop_back();
        qmin.push_back({i,a[i]});

        if(qmax.front().first <= i-k)
            qmax.pop();
        if(qmin.front().first <= i-k)
            qmin.pop();
    }
    
    rmax.push_back(qmax.front().second);
    rmin.push_back(qmin.front().second);
    
    for(auto item: rmin)
        printf("%d ", item);
    cout<<endl;
    for(auto item: rmax)
        printf("%d ", item);
    
    return 0;
}