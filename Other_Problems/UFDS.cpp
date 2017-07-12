/*
    Ngô Hồng Phúc - ngohongphuc2001
    UNION-FINDING DIJOINTSET CP3RD
*/
#include<bits/stdc++.h>

using namespace std;

class ufds{
    vector<int> p, r, setSize;
    int numSet;
    public ufds(int n){
        p.assign(n, 0); r.assign(n, 0);  setSize.assign(n, 1);
        numSet = n;
        for(int i = 0; i < n; ++i) p[i] = i;
    }
    int findSet(int i){
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool SameSet(int i, int j){
        return(findSet(i) == findSet(j));
    }
    void unionset(int i, int j){
        if(findSet(i) != findSet(j)){
            numSet--;
            int x = findSet(i);
            int y = findSet(j);
            if(r[x] > r[y]){
                p[y] = x;
                setSize[x] += setSize[y];
            } else {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main(){

}
