/*
    Ngô Hồng Phúc - ngohongphuc2001
    10986 - Sending email GNU C++14
*/

#include<bits/stdc++.h>
#define INF 1000000000

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int N;

int main(){
    //freopen("stdin.inp", "r", stdin);
    cin>>N;
    for(int i = 1; i <= N; ++i){
        int n, m, S, T;
        cin>>n>>m>>S>>T;
        vector<vii> adjlist;
        adjlist.assign(n, vii());
        int u, v, w;
        for(int j = 1; j <= m; ++j){
            cin>>u>>v>>w;
            adjlist[u].push_back(ii(v, w));
            adjlist[v].push_back(ii(u, w));
        }
        vi dist(n, INF); dist[S] = 0;
        priority_queue< ii, vector<ii>, greater<ii> > pg; pg.push(ii(0, S));
        while(pg.size() != 0){
            ii temp = pg.top();
            int d = temp.first, u = temp.second;
            pg.pop();
            if(d > dist[u]) continue;
            for(int j = 0; j < adjlist[u].size(); ++j){
                ii v = adjlist[u][j];
                if(dist[u] + v.second < dist[v.first]){
                    dist[v.first] = dist[u] + v.second;
                    pg.push(ii(dist[v.first], v.first));
                }
            }
        }
        cout<<"Case #"<<i<<":"<<" ";
        if(dist[T] != INF){
            cout<<dist[T];
        } else cout<<"unreachable";
        cout<<endl;
    }
}
