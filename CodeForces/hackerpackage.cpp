#include<bits/stdc++.h>

using namespace std;

class nghi{
    public: int l, r, c;
    public: void set(int l, int r, int c){
        this->l = l;
        this->r = r;
        this->c = c;
    }
};

bool cmp(nghi a, nghi b){
    if((a.r - a.l) == (b.r - b.l)){
        return a.c < b.c;
    }
    return ((a.r - a.l) < (b.r - b.l));
}

int n, x;
int ans = 2000000001;
vector<nghi> v;
map<int, vector<nghi> > mm;
set<int> uni;

int main(){
    //freopen("stdin.inp", "r", stdin);
    scanf("%i%i", &n, &x);
    for(int i = 0; i < n; ++i){
        nghi temp;
        scanf("%i%i%i", &temp.l, &temp.r, & temp.c);
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; ++i){
        mm[v[i].r - v[i].l + 1].push_back(v[i]);
        uni.insert(v[i].r - v[i].l + 1);
    }
    for(set<int>::iterator i = uni.begin(); i != uni.end(); ++i){
        if(mm[x - *i].size() == 0) continue;
        for(int j = 0; j  < mm[*i].size(); ++j){
            for(int z = 0; z < mm[x - *i].size(); ++z){
                if(mm[*i][j].l > mm[x - *i][z].r || mm[x - *i][z].l > mm[*i][j].r){
                    ans = min(ans, mm[*i][j].c + mm[x - *i][z].c);
                    break;
                }
            }
        }
    }
    if(ans != 2000000001)printf("%i", ans); else printf("-1");
}
