#include <bits/stdc++.h>

using namespace std;

int n;
string s;
bool flag;
int cnt;

int main(){
	cin>>n;
	cout<<n<<endl;
	while(n--){
		cin>>s;
		flag = false;
		cnt = 0;
		for(int i = 0; i < s.length(); ++i){
			if(flag && s[i] == '0'){
				++cnt;
			}
			if(flag && s[i] == '1') break;
			if(i == 0 && s[i] == '1') flag = true;
			if(flag && i != 0 && s[i - 1] != s[i]) flag = true;
		}
		cout<<cnt;
	}
}
