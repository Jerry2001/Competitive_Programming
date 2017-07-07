/*
    Ngô Hồng Phúc - ngohongphuc2001
    1203	Argus
*/
#include<bits/stdc++.h>

using namespace std;

class anh{
    public : int id, p, i;
    public : void setx(int id,int p,int i){
        this->id = id;
        this->i = i;
        this->p = p;
    }
};

struct cmp{
    bool operator()(anh a, anh b){
        if(a.i != b.i){
            return a.i > b.i;
        } else return a.id > b.id;
    }
};

int main(){
    //freopen("stdin.inp", "r", stdin);
    priority_queue<anh, vector<anh>, cmp> q;
    string s;
    int id, p;
    anh temp;
    while(cin >> s){
        if(s == "#") break;
        cin>>id>>p;
        temp.setx(id, p, p);
        q.push(temp);
    }
    cin>>id;
    while(id--){
        cout<<q.top().id<<'\n';
        temp = q.top();
        q.pop();
        temp.i += temp.p;
        q.push(temp);
    }
}
