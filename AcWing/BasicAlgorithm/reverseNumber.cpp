// 求解逆序对的数量
#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1e5;
int a[N], temp[N];
unsigned long res = 0;
int n;

void mergesort(int num[], int l, int r){
    if(l >= r)
        return;
    int mid = (l+r)>>1;
    mergesort(num, l, mid);
    mergesort(num, mid+1, r);
    int i = l, j = mid+1, k=0;
    while(i<=mid && j<=r){
        if(num[i] <= num[j])
            temp[k++] = num[i++];
        else{
            temp[k++] = num[j++];
            res += mid - i + 1;
        }
    }
    while(i<=mid)
        temp[k++] = num[i++];
    while(j<=r)
        temp[k++] = num[j++];
    for(int i=0, j=l; j<=r; ++i, ++j)
        num[j] = temp[i];
}

int main(){
    freopen("./unorderArray.txt", "r", stdin);
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%d", &a[i]);
        printf("%d ", a[i]);
    }

    mergesort(a, 0, n-1);

    // bool flag = false;
    // while(!flag){
    //     flag = true;
    //     for(int i=1; i<n; ++i){
    //         if(a[i-1] > a[i]){
    //             flag = false;
    //             swap(a[i-1], a[i]);
    //             ++res;
    //         }
    //     }
    //     --n;
    // }

    cout<<endl<<"res = "<<res<<endl;
    return 0;
}