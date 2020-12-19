#include<bits/stdc++.h>

/*
    Ngô Hồng Phúc - ngohongphuc2001
    Minstack from GeeksForGeeks
*/
using namespace std;

class minStack{
    public: stack<int> s;
    int minx;
    public: void getMin(){
        cout<<minx<<'\n';
    }
    public: void peek(){
        int i = s.top();
        (i < minx) ? cout<< minx : cout<<i<<endl;
    }
    public: void pop(){
        int i = s.top();
        s.pop();
        if(i < minx){
            minx = minx * 2 - i;
        }
    }
    public: void push(int x){
        if(x < minx){
            s.push(2 * x - minx);
            minx = x;
        } else s.push(x);
    }
};

int main(){
    minStack s;
    s.push(2);
    s.push(1);
    //s.push(5);

}
