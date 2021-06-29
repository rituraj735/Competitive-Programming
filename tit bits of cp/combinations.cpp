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
ll factorial[10000001];
ll inv[10000001];
ll inv_fac[10000001];
ll numberofways(ll n , ll r){
	return factorial[n]%mod*inv_fac[n-r]%mod*inv_fac[r]%mod;
}
int main(){
  IOS;
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  factorial[0]= factorial[1]= 1;
  for(ll i=2; i<=10000000; i++){
  	factorial[i] = (factorial[i-1]*i)%mod;
  }
  inv[1]= 1;
  for(ll i=2; i<=10000000; i++){
  	 inv[i] = (mod - ((mod/i) * (inv[mod%i]))%mod+mod) % mod;
  }
  inv_fac[0]=1;
  for(ll i=1; i<=10000000; i++){
  	inv_fac[i] = (inv[i]*inv_fac[i-1])%mod;
  }
  ll a, b, n, k;
  cin>>a>>b>>n>>k;
  cout<<numberofways(n,k);
  return 0;

}