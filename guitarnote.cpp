#include <bits/stdc++.h>

using namespace std;

char b, changednote[7], re;
int n, i, giu, change, strings, note, j;
string s = "0EBGDAE";
bool bl = false, con = true;

void check(){
  bl = false;
  for(int o = 0; o <= note; o++){
  if(s[j] == changednote[o]){
    bl = true;
    break;
    }
  }
}

int main(){
  while(con == true){
  cout<<"Note in Vietnamese"<<endl;
  cout<<"C: Do"<<endl<<"D: Re"<<endl<<"E: Mi"<<endl<<"F: Fa"<<endl<<"G: Sol"<<endl<<"A: La"<<endl<<"B: Si";
  cout<<endl;
  while(n < 1 || n > 6){
  cout<<"Input numbers of string:"<<endl;
  cin>>n;
  if(n < 1 || n > 6) cout<<"Out of string number. Retry"<< endl;
  }
  while(i >= 6 || i <= 0 || n + i > 7){
  cout<<"Start from string:"<<endl;
  cin>>i;
  if(i >= 6 || i <= 0 || n + i > 7) cout<<"Couldn't start at this position. Retry"<<endl;
  }
  cout<<"Number of changed strings:"<<endl;
  change = 7;
  while(change > n ){
  cin>>change;
  if (change > n) {
    cout<<"Out of string number. Retry"<<endl;
    continue;
  }
  for(int j = 0; j < change; j++){
    cout<<"Change string ";
    cin>>strings;
    cout<<" "<<"from "<<s[strings]<<" "<<"to ";
    cin>>b;
    cout<<endl;
    if (int(b) >= 97) b = char(int(b) - 32);
    s[strings] = b;
    }
  }
  note = 8;
  while(note > 7 || note < 0){
  cout<<"Number of bold note:"<<endl;
  cin>>note;
  if (note > 7 || note < 0) {
    cout<<"Out of note. Retry.";
    continue;
  }
  for(int k = 0; k < note; k++){
    cout<<"Note: ";
    cin>>changednote[k];
    }
  }
  cout<<"          ";
  for(int j = 0; j <= 12; j++){
    if(j >= 10) cout<<j<<"  "; else
    cout<<j<<"   ";
  }
  cout<<endl;
  for(j = i; j < i + n; j++){
      cout<<"String "<<j<<":"<<" ";
    for(int k = 0 ; k <= 12; k++){
      check();
      if (bl == true) {
        cout<<s[j]<<"*"<<"|"<<" ";
      } else
      cout<<s[j]<<" "<<"|"<<" ";
      if (s[j] != 'E' && s[j] != 'B') {
        giu = int(s[j]);
        giu++;
        k++;
        if (k <= 12) cout<<s[j]<<'#'<<"|"<<" ";
        s[j] = char(giu);
        if (s[j] == 'H') s[j] = 'A';
      } else {
        giu = int(s[j]);
        giu++;
        s[j] = char(giu);
      }
    }
    cout<<endl;
  }
  cout<<endl;
  cout<<"Retry = Press Y + enter. Quit = Press N + enter: ";
  cin>>re;
  if(re == 'Y') re = true; else re = false;
  cout<<endl;
}
  return 0;
}
