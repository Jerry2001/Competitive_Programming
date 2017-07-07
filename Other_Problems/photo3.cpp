/*
    Ngô Hồng Phúc - ngohongphuc2001
    #greedy
*/
#include<bits/stdc++.h>

using namespace std;

int cnt[4][4], n, a[1100];

int main(){
    freopen("photo3.inp", "r", stdin);
    freopen("photo3.out", "w", stdout);
    scanf("%i", &n);
    for(int i = 0; i < n; ++i){
        scanf("%i", &a[i]);
        ++cnt[0][a[i]];
    }
    for(int i = 0; i < cnt[0][1]; ++i){
        ++cnt[1][a[i]];
    }
    for(int i = cnt[0][1]; i < cnt[0][1] + cnt[0][2]; ++i){
        ++cnt[2][a[i]];
    }
    for(int i = cnt[0][1]+cnt[0][2]; i < cnt[0][1] + cnt[0][2] + cnt[0][3]; ++i){
        ++cnt[3][a[i]];
    }
    int ans = min(cnt[1][3], cnt[3][1]) + min(cnt[2][3], cnt[3][2]) + min(cnt[1][2], cnt[2][1]) + 2 * abs(cnt[1][2] - cnt[2][1]);
    printf("%i", ans);
}


