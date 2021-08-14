#include<bits/stdc++.h>

using namespace std;

int bin_search(vector<int>& nums, int val){
    int l = 0, r = nums.size()-1, m;
    while(l < r){
        m = (l + r) / 2;
        if(nums[m] < val){
            l = m + 1;
        } else if(nums[m] > val){
            r = m - 1;
        } else return m;
    }
    if(nums[l] != val) return -1;
    return l;
}

int main(){
    int target = 0;
    vector<int> nums = vector<int>{1};
    vector<int> nums_sorted = nums;
    sort(nums_sorted.begin(), nums_sorted.end());

    int k = bin_search(nums_sorted, nums[0]);
    int ans = bin_search(nums_sorted, target);
    if(ans == -1) return ans;
    if(ans >= k){
        ans -= k;
    } else ans += (nums.size() - k);
    cout<<ans;
    return ans;
}
