#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> l_product, r_product, ans;
    int final_ans = nums[0];
    if(nums.size() == 1) return final_ans;
    ans.resize(nums.size());

    l_product.resize(nums.size());
    l_product[0] = nums[0];

    r_product.resize(nums.size());
    r_product[nums.size() - 1] = nums[nums.size() - 1];


    for(int i = 1; i < nums.size(); ++i){
        l_product[i] = max(l_product[i - 1] + nums[i], nums[i]);
    }

    for(int i = nums.size() - 2; i >= 0; --i){
        r_product[i] = max(r_product[i + 1] + nums[i], nums[i]);
    }

    for(int i = 0; i < nums.size(); ++i){
        if(i == 0) ans[i] = r_product[i];
        else if(i == nums.size() - 1) ans[i] = l_product[i];
        else ans[i] = l_product[i] + r_product[i] - nums[i];
        final_ans = max(ans[i], final_ans);
    }
    //cout<<final_ans;
    return final_ans;
}
