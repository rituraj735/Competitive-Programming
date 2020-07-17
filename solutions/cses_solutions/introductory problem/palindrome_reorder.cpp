// Problem statement @: https://cses.fi/problemset/task/1755
#include <bits/stdc++.h>
using namespace std;
# define ll  long long  int
# define ld  long double
#define fin0(i,a,b,c) for(int i=a;i<b;i+=c)
#define fin1(i,a,b,c) for(int i=a;i<=b;i+=c)
#define fde0(i,a,b,c) for(int i=a;i>b;i-=c)
#define fde1(i,a,b,c) for(int i=a;i>=b;i-=c)
#define vi vector<int>
#define vll vector<ll>
#define vboo vector<bool>
#define all(a) a.begin(),a.end()
# define pb push_back
# define pp pop_back
# define ff first
# define ss second
# define mp make_pair
# define ac accumulate
# define mod 1000000007
# define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define t     \
    int t;    \
    cin >> t; \
    while (t--)
# define trace1(x)                cerr << #x << ": " << x << "\n";
# define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << "\n";
# define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n";
# define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << "\n";

void getPalindrome(string s){
    unordered_map<char,int> mp;
    int n= s.size();
    fin0(i,0,n,1){
       mp[s[i]]++;
     }
    int oddOccurrences =0;
    char oddChar;
    for(auto x:mp){
        if(x.second % 2){
            oddOccurrences++;
            oddChar= x.first;
        }
    }
    if((oddOccurrences>1)|| ((oddOccurrences==1) && (n%2==0))){
       cout<<"NO SOLUTION";
       }
       else{
    string firstHalf="", secondHalf="";
    for(auto x:mp){
        string s(x.second/2, x.first);
        firstHalf= firstHalf+s;
        secondHalf= s+secondHalf;
    }
    cout<<((oddOccurrences==1)?(firstHalf+oddChar+secondHalf):(firstHalf+secondHalf));}
}
int main(){
  IOS;
  string s;
  cin>>s;
  getPalindrome(s);
  return 0;
}
