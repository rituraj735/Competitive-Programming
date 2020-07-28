// Problem Statement @: https://www.spoj.com/problems/RMQSQ/

#include <bits/stdc++.h>
using namespace std;
# define ll long long int
# define ld long double
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
#define MAXN 100000

int st[MAXN][100];

void compute(int array[],int n){
    fin0(i,0,n,1){
       st[i][0]= array[i];
    }
    int K= log2(n);
    for(int j=1;j<=K;j++){
        for(int i=0;i+(1<<j)<=n;i++){
            st[i][j]= min(st[i][j-1],st[i+(1<<j-1)][j-1]);
        }
    }
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  fin0(i,0,n,1){
    cin>>arr[i];
    }
    compute(arr,n);
   int q;
   cin>>q;
   while(q--){
        int R,L;
   cin>>L>>R;
    int K= log2(R-L+1);
    int minimum= min(st[L][K],st[R-(1<<K)+1][K]);
    cout<<minimum<<"\n";
   }
   return 0;
}
