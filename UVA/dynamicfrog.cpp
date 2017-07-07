/*
    Ngô Hồng Phúc - ngohongphuc2001
    11157	Dynamic Frog  GNU C++14
*/
#include<bits/stdc++.h>

using namespace std;

int T, n, d;

int main(){
        //freopen("stdin.inp", "r", stdin);
        cin>>T;
        for(int o = 1; o <= T; ++o){
            int maxn = -1;
            cin>>n>>d;
            vector< pair<int, char> > j;
            j.push_back(pair<int, char>(0, 'B'));
            for(int i = 1; i <= n; ++i){
                char a, b; int c;
                cin>>a>>b;
                cin>>c;
                j.push_back(pair<int, char>(c, a));
            }
            j.push_back(pair<int, char>(d, 'B'));
            for(int i = 0; i < j.size() - 1; ++i){
                if(j[i + 1].second == 'B'){
                    maxn = max(maxn, abs(j[i].first - j[i + 1].first));
                } else {
                    maxn = max(maxn, abs(j[i].first - j[i + 2].first));
                }
            }
            cout<<"Case "<<o<<": "<<maxn<<endl;
        }
}
