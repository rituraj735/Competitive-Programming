// Problem statement @: https://cses.fi/problemset/task/1072/
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

int main(){
  IOS;
  // This problem could have recursive solution but here I solve it in O(n) time using simple combinatronics
  ll n;
  cin>>n;
  fin1(i,1,n,1){
      cout<< (((1LL*i*i)*(1LL*i*i -1)/2) - (4*1LL*(i-1)*(i-2)))<<"\n";
}

  // Total number of unique positions of the two knights: (n^2 * (n^2 -1))/2
  // Total positions in which the knights attack each other in a 3x2 or 2x3 grid : 4*(n-1)*(n-2)
  // Thus the total non-attacking positions : {(n^2 * (n^2 -1))/2} - {4*(n-1)*(n-2)}
  return 0;
}
