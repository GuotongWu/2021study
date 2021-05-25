#include<iostream>
using namespace std;

void quicksort(int nums[], int l, int r){
    if (l>=r) 
        return;
    int left = l-1, right = r+1;
    int x = nums[left+right>>1];
    while(left<right){
        do ++left; while(nums[left] < x);
        do --right; while(nums[right] > x);
        if(left < right) 
            swap(nums[left], nums[right]);
    }
    quicksort(nums, l, right);
    quicksort(nums, right+1, r);    
}

int main(){
    int nums[] = {1,1};
    quicksort(nums, 0, 1);
    for(int i=0; i<2; ++i)
        cout<<nums[i]<<" ";
    return 0;
}