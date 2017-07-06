/*
    Ngô Hồng Phúc ngohongphuc2001
    822B - Crossword solving
    CPP
*/

#include<bits/stdc++.h>

using namespace std;

string s, t;
int sum, pos, ans = 1005;

int main(){
    cin>>sum>>sum>>s>>t;
    for(int i = 0; i <= t.length() - s.length(); ++i){
        sum = 0;
        for(int j = i; j < s.length() + i; ++j){
            if(t[j] != s[j - i]) {
                ++sum;
            }
        }
        if(sum < ans){
            ans = sum;
            pos = i;
        }
    }
    cout<<ans<<endl;
    for(int i = pos; i <= pos; ++i){
        sum = 0;
        for(int j = i; j < s.length() + i; ++j){
            if(t[j] != s[j - i]) {
               cout<<j-i + 1<<" ";
            }
        }
    }
}
