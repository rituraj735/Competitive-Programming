// Problem Statement @: https://cses.fi/problemset/task/1634/
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
const ll INF = 1e18;

int main(){
  IOS;
  ll n;
  cin>>n;
  ll x;
  cin>>x;
  vll coins;
  fin0(i,0,n,1){
     ll num;
     cin>>num;
     coins.pb(num);
  }
  ll solve[x+1];

  solve[0] = 0;
  fin1(i,1,x,1){
      solve[i]= INF;
      for(auto c:coins){
        if(i-c>= 0)
             solve[i] = min(solve[i],solve[i-c]+1);

      }
       }
       if(solve[x]>1000001)
          cout<<-1;
       else
         cout<<solve[x];
  return 0;
}
