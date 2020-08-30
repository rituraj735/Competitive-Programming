// Problem Statement @: https://www.codechef.com/problems/VCAKE
// Problem Name: VCake 

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
const ll INF= 1e18;

bool check(ll r, ll c, ll p, ll q){
     if(q%r==0) return true;
     if(q%c==0) return true;
     return false;
}


int main(){
  IOS;
  t{
     ll r,c ;
     ll m,k,j;
     cin>>r>>c>>m>>k>>j;
     if((r*c)!=m+k+j)
        cout<<"No\n";
     else if(m%r==0 && check(r,(c-m/r),k,j))
        cout<<"Yes\n";
     else if(m%c==0 && check((r-m/c),c,k,j))
        cout<<"Yes\n";
     else if(k%r==0 && check(r,(c-k/r),m,j))
        cout<<"Yes\n";
     else if(k%c==0 && check((r-k/c),c,m,j))
        cout<<"Yes\n";
     else if(j%r==0 && check(r,(c-j/r),k,m))
        cout<<"Yes\n";
     else if(j%c==0 && check((r-j/c),c,k,m))
        cout<<"Yes\n";
     else
        cout<<"No\n";
  }
  return 0;
}
