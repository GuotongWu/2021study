#include<iostream>
using namespace std;

const int N = 7;
int nums[N] = {8,7,10,5,2,7,3};
int temp[N];

void mergesort(int nums[], int l, int r)
{
    if(l>=r)
        return;
    int mid = l+r>>1;
    mergesort(nums, l, mid);
    mergesort(nums, mid+1, r);
    int k=0, i=l, j=mid+1;
    while(i<=mid && j<=r){
        if(nums[i] <= nums[j]) 
            temp[k++] = nums[i++];
        else 
            temp[k++] = nums[j++];
    }
    while(i<=mid)
        temp[k++] = nums[i++];
    while(j<=r)
        temp[k++] = nums[j++];
    for(int i=l, j=0; i<=r; ++i,++j)
        nums[i] = temp[j];
}

int main(){
    mergesort(nums, 0, N-1);
    for(int i=0; i<N; ++i){
        cout<<nums[i]<<" ";
    }
    return 0;
}