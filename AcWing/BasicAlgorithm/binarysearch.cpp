#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1e5;
int a[N], b[N];
int n;

int bin_search1(int num[], int l, int r, int t){
    if(l >= r)
        return -1;
    while(l < r){
        int mid = (l+r)>>1;
        if(num[mid] >= t) // on the left
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int bin_search2(int num[], int l, int r, int t){
    if(l >= r)
        return -1;
    while(l < r){
        int mid = (l+r+1)>>1;
        if(num[mid] <= t) // on the right
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int main(){
    freopen("./orderArray.txt", "r", stdin);
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    
    return 0;
}