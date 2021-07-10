#include<iostream>
#include<vector>
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

void quicksort(vector<int> & nums, int l, int r){
        if(l>=r)
            return;
        int ll = l-1, rr = r+1;
        int mid = nums[ll+rr>>1];
        while(ll < rr){
            do ++ll; while(nums[ll] < mid);
            do --rr; while(nums[rr] > mid);
            if(ll < rr)
                swap(nums[ll], nums[rr]);
        }
        quicksort(nums, l, rr);
        quicksort(nums, rr+1, r);
    }

int main(){
    // int nums[] = {10,9,8,5,3,6,2,1,5,3,2};
    vector<int> nums = {10,9,8,5,3,6,2,1,5,3,2};
    quicksort(nums, 0, 10);
    for(int i=0; i<11; ++i)
        cout<<nums[i]<<" ";
    return 0;
}