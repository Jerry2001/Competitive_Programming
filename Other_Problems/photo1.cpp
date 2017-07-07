#include<bits/stdc++.h>

using namespace std;


bool cmp(pair<int, int> x, pair<int, int> y){
    return x.second < y.second;
}

int n, k, a, b;
vector<pair<int, int> > v;

void QSort(int leftx, int rightx){
    if(leftx >= rightx) return;
    pair<int, int> pivot = v[(leftx + rightx) / 2];
    int i = leftx, j = rightx;
    while(i <= j){
        while(cmp(v[i], pivot)) ++i;
        while(cmp(pivot, v[j])) --j;
        if (i <= j){
            swap(v[i], v[j]);
            ++i; --j;
        }
    }
    QSort(leftx , j); QSort(i, rightx);
}

int main(){
    freopen("photo1.inp", "r", stdin);
    freopen("photo1.out", "w", stdout);
    scanf("%i%i", &n, &k);
    v.resize(k);
    for(int i = 0; i < k; ++i){
        scanf("%i%i", &v[i].first, &v[i].second);
        if(v[i].first > v[i].second) swap(v[i].first,v[i].second);
    }
    //sort(v.begin(), v.end(), cmp);
    QSort(0, k - 1);
    /*for(int i = 0; i < k; ++i){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }*/
    int l = 1, ans = 1, r = n;
    for(int i = 0; i < k; ++i){
        if(v[i].first >= l && v[i].second <= r){
            ++ans;
            l = v[i].second;
            r = n;
            //cout<<x<<endl;
        }
    }
    printf("%i", ans);
}

