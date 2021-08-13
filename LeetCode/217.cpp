#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> nums = vector<int>{1,2,3,1};
    map<int, int> checker;

    for(int i = 0; i < nums.size(); ++i){
        if(checker[nums[i]] == 1){
            return true;
        }
        checker[nums[i]]++;
    }
    return false;
}
