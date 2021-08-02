#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1e5;
int a[N], b[N];
int n;

// 寻找左边小于等于目标值的最大值
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

// 寻找右边大于等于目标值的最小值
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
        printf("%d ",a[i]);
    }
    cout<<endl<<bin_search1(a, 0, n-1, 3);
    cout<<endl<<bin_search2(a, 0, n-1, 3);
    return 0;
}