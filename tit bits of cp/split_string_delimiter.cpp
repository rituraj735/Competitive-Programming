#include <bits/stdc++.h>
using namespace std;

const ll INF= 1e18;
#define vvi vector<vector<int>>

// How to split a string in C++
void tokenizer(string str, string del =" "){
  int start = 0;
  int end = str.find(del);
  while(end != -1){                             // Usually string::npos is returned but since it is unsigned, -1 works 
    string s = str.substr(start,end-start);
    cout<<s<<" end: "<<end<<"\n";
    start = end + del.size();
    end = str.find(del, start);
  }

}
int main(){
  IOS;
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  string str;
  cin>>str;
  tokenizer(str,"$%");
  return 0;
}
