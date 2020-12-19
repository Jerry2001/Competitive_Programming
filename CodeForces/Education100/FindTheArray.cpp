#include<bits/stdc++.h>

using namespace std;

int n, t;
vector<int> v;

int main(){
	//freopen("B.inp", "r", stdin);
    //freopen("B.out", "w", stdout);
    cin>>t;
    while(t--){
    	cin>>n;
    	v.resize(n);
    	int sum = 0;
    	for(int i = 0; i < n; ++i){
    		cin>>v[i];
    		sum += v[i];
    	}
    	vector<int> ans;
    	ans.resize(n);
    	int dummy = 0;
    	int curr = v[0];
    	cout<<curr<<" ";
    	for(int i = 1; i < n; ++i){
    		if(curr > v[i]){
    			int l, r;
    			l = r = (int)(curr / v[i]);
    			bool flag = false;
    			for(int j = 0; j < trunc(sqrt((int)(curr / v[i]))); ++j){
    				if(r != 0 && l != 0 && curr % r == 0 && curr % l == 0){
    					if(abs(curr/r - v[i]) < abs(curr/l - v[i])){
    						curr /= r;
    					} else curr /= l;
    					break;
    				}
    				if(r != 0 && curr % r == 0){
    					curr /= r;
    					break;
    				}
    				if(l != 0 && curr % l == 0){
    					curr /= l;
    					break;
    				}
    				if(l > 0) --l;
    				++r;
    			}
    		} else if(curr < v[i]){
    			 if(abs(((int)(v[i] / curr) + 1) * curr - v[i]) < abs((int)(v[i] / curr) * curr - v[i])
    			 	&& ((int)(v[i] / curr) + 1) * curr<= 1e9){
    			 	curr *= (int)(v[i] / curr) + 1;
    			 } else curr *= (int)(v[i] / curr);
    		} 
    		dummy += abs(v[i] - curr) * 2;
    		cout<<curr<<" ";
    	}
    	cout<<endl;
    	//cout<<"\n"<<sum<<" "<<dummy<<endl;
    }
}