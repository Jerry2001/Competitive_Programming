#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int>prices = vector<int>{7,1,5,3,6,4};
    vector<int>max_array;
    max_array.resize(prices.size());
    max_array[prices.size() - 1] = prices[prices.size() - 1];

    for(int i = prices.size() - 2; i >= 0; --i){
        max_array[i] = max(max_array[i + 1], prices[i]);
    }

    for(int i = 0; i < prices.size() - 1; ++i){
        res = max(res, max_array[i + 1] - prices[i]);
    }
    cout<<res;
}
