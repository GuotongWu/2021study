#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1e5+10;
int number[N], temp[N];
int n;

void mergesort(int number[], int l, int r){
    if(l >= r)
        return;
    int mid = (l + r) >> 1;
    mergesort(number, l, mid);
    mergesort(number, mid+1, r);
    int i = l, j = mid+1, k = 0;
    while(i<=mid && j<=r){
        if(number[i] <= number[j])
            temp[k++] = number[i++];
        else
            temp[k++] = number[j++];
    }
    while(i <= mid)
        temp[k++] = number[i++];
    while(j <= r)
        temp[k++] = number[j++];
    for(int i=0,j=l; j<=r; )
        number[j++] = temp[i++];
}

int main(){
    freopen("./unorderArray.txt", "r", stdin);
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
        scanf("%d", &number[i]);

    mergesort(number, 0, n-1);

    for(int i=0; i<n; ++i)
        printf("%d ", number[i]);

    return 0;
}