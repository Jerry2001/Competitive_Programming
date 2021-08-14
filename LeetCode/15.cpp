
#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> nums = vector<int>{1};
    map<int, int> cnt;
    set<vector<int>, int> flag;
    vector<vector<int>> ans;

    for(int i = 0; i < nums.size(); ++i){
        ++cnt[nums[i]];
    }

    for(int i = 0; i < nums.size(); ++i){
        for(int j = i + 1; j < nums.size() - 1; ++j){
            int sum = nums[i] + nums[j];
            cnt[nums[i]]--; cnt[nums[j]]--;
            if(cnt[-sum] > 0){
                vector<int> temp_ans = vector<int>{nums[i], nums[j], -sum};
                sort(temp_ans.begin(), temp_ans.end());
                if(flag[temp_ans] == 0){
                    ++flag[temp_ans];
                    ans.push_back(temp_ans);
                }
            }
            cnt[nums[i]]++; cnt[nums[j]]++;
        }
    }

    return ans;
}
