#include<bits/stdc++.h>

using namespace std;

int n, k, a, b;

bool last_check(string lst){
    int sum = 0;
    for(int i = 0; i < lst.length(); ++i){
        ++sum;
        if(i == lst.length() - 1) break;
        if(lst[i + 1] != lst[i]){
            if(sum > k) return false;
            sum = 0;
        }
    }
    if(sum > k) return false;
    return true;
}

int main(){
    //freopen("stdin.inp", "r", stdin);
    cin>>n>>k>>a>>b;
    string s;
    int dem = 0;
    if(a < b){
        s+='A';
        for(int i = 0; i < b; ++i){
            s+= 'B';
            ++dem;
            if(dem == k && a > 0){
                s+= 'G';
                --a;
                dem = 0;
            }
        }
        dem = 0;
        string ans;
        for(int i = 1; i <= s.length(); ++i){
            if(s[i] == 'B' && s[i] != s[i - 1]){
                int temp = 0;
                temp += dem;
                while(a >= 1 && temp < k){
                    ans+= 'G';
                    a--;
                    temp++;
                }
                dem = 0;
            }
            if(s[i] == 'G') ++dem, ans+= s[i];
            if(s[i] == 'B') ans+=s[i];
        }
        if(a == 0 && last_check(ans))cout<<ans; else cout<<"NO";
    } else {
        s+='A';
        for(int i = 0; i < a; ++i){
            s+= 'G';
            ++dem;
            if(dem == k && b > 0){
                s+= 'B';
                dem = 0;
                --b;
            }
        }
        dem = 0;
        string ans;
        for(int i = 1; i <= s.length(); ++i){
            if(s[i] == 'G' && s[i] != s[i - 1]){
                int temp = 0;
                temp += dem;
                while(b >= 1 && temp < k){
                    ans+= 'B';
                    b--;
                    temp++;
                }
                dem = 0;
            }
            if(s[i] == 'B') ++dem, ans+= s[i];
            if(s[i] == 'G') ans+=s[i];
        }
        if(b == 0 && last_check(ans))cout<<ans; else cout<<"NO";
    }
}
