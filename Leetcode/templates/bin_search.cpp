#include<iostream>
using namespace std;

const int N = 8;
int nums[N] = {1, 3, 4, 4, 4, 5, 8, 9};

int bin_search1(int nums[], int l, int r, int target){
    if (l>=r)
        return -1;
    while(l<r){
        int mid = l+r>>1;
        if(nums[mid] >= target)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
    
}

int bin_search2(int nums[], int l, int r, int target)
{
    if(l>=r)
        return -1;
    while(l<r){
        int mid = l+r+1>>1;
        if(nums[mid] <= target)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int main()
{
    cout<<bin_search1(nums, 0, N-1, 4)<<endl;
    cout<<bin_search2(nums, 0, N-1, 4)<<endl;
    return 0;
}