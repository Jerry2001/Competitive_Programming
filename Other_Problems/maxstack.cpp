/*
    Ngô Hồng Phúc - ngohongphuc2001
    Maxstack from GeeksForGeeks
*/
#include <bits/stdc++.h>

using namespace std;

class maxstack {
    public: stack<int> q;
    int maxl = -1000000000;
    public: void push(int x){
        if(x > maxl) {
            q.push(x * 2 + maxl);
            maxl = x;
        } else {
            q.push(x);
            }
    }
    public: void pop(){
        int i = q.top();
        if(i > maxl){
            maxl = i - (2 * maxl);
        }
        q.pop();
    }
    public: void peek(){
        int i = q.top();
        if(q.size() == 1){
            cout<<maxl<<endl;
            return;
        }
        (i < maxl) ? cout<<i : cout<<maxl;
        cout<<endl;
    }
    public: void getMax(){
        cout<<maxl<<endl;
    }
};

int main(){
//09191376666
    maxstack s;
    s.push(1);
    s.peek();
    s.getMax();
    s.push(-1);
    s.push(2);
    s.getMax();
    s.pop();
    s.getMax();
    s.peek();
    s.pop();
    s.getMax();
    s.peek();
}
