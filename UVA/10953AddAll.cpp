/*
    Ngô Hồng Phúc - ngohongphuc2001
    10954	Add All
*/
#include<bits/stdc++.h>

using namespace std;

int n, ans;

int main(){
    //freopen("stdin.inp", "r", stdin);
    while(cin >> n){
        ans = 0;
        if(n == 0) break;
        int temp;
        priority_queue<int, vector<int>, greater<int> > q;
        int a, b;
        for(int i = 0; i < n; ++i){
            cin>>temp;
            q.push(temp);
        }
        while(q.size() > 1){
            a = q.top(); q.pop();
            b = q.top(); q.pop();
            //cout<<a<<" "<<b<<endl;
            ans += a + b;
            q.push(a + b);
        }
        cout<<ans<<endl;
    }
}
