#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> nums = vector<int>{-1,1,0,-3,3};
    vector<int> l_product, r_product, ans;

    ans.resize(nums.size());

    l_product.resize(nums.size());
    l_product[0] = nums[0];

    r_product.resize(nums.size());
    r_product[nums.size() - 1] = nums[nums.size() - 1];


    for(int i = 1; i < nums.size(); ++i){
        l_product[i] = l_product[i - 1] * nums[i];
    }

    for(int i = nums.size() - 2; i >= 0; --i){
        r_product[i] = r_product[i + 1] * nums[i];
    }

    for(int i = 0; i < nums.size(); ++i){
        if(i == 0) ans[i] = r_product[i + 1];
        else if(i == nums.size() - 1) ans[i] = l_product[i - 1];
        else ans[i] = l_product[i - 1] * r_product[i + 1];
        cout<<ans[i]<<" ";
    }

    return ans;
}
