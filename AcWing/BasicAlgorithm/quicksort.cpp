#pragma GCC optimize(2)

#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1e5;
int a[N];
int n;

void quicksort(int a[], int l, int r){
    if(l >= r)
        return;
    int begin = l - 1;
    int end = r + 1;
    int mid = (begin + end) >> 1;
    while(begin < end){
        do ++begin; while(a[begin] < a[mid]);
        do --end; while(a[end] > a[mid]);
        if(begin < end)
            swap(a[begin], a[end]);
    }
    quicksort(a, l, end);
    quicksort(a, end+1, r);
}

int main(){
    freopen("./unorderArray.txt", "r", stdin);
    
    cin>>n;
    for(int i=0; i<n; ++i)
        cin>>a[i];
    
    quicksort(a, 0, n-1);

    for(int i=0; i<n; ++i)
        printf("%d ", a[i]);
    return 0;
}