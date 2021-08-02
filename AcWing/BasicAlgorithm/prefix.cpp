#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1e5+10;
int a[N], p[N];

int main(){
    freopen("./unorderArray.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%d", &a[i]);
        printf("%d ", a[i]);
    }

    cout<<endl;
    p[0] = a[0];
    for(int i=1; i<n; ++i)
        p[i] = p[i-1] + a[i];
    for(int i=0; i<n; ++i)
        printf("%d ", p[i]);

    // if you want to get the result of a[3] +...+a[8]
    puts("");
    printf("%d", p[8]-p[3-1]);
    return 0;
}