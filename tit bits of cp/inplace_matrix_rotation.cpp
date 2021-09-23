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
using vvi = vector<vector<int>>;
vector<bool> vis;
int n;
void rotate_anti(vvi &arr){
  fin0(i,0,n/2,1){
    fin0(j,i,n-i-1,1){
      int temp = arr[i][j];
      arr[i][j] = arr[j][n-1-i];
      arr[j][n-1-i] = arr[n-1-i][n-1-j];
      arr[n-1-i][n-1-j] = arr[n-1-j][i];
      arr[n-1-j][i] = temp;
    }
  }
}

void print(vvi arr){
  fin0(i,0,n,1){
    fin0(j,0,n,1){
      cout<<arr[i][j]<<" ";
    }
    cout<<"\n";
  }
}

void rotate_clock(vvi &arr){
  fin0(i,0,n/2,1){
    fin0(j,i,n-i-1,1){
      int temp = arr[n-1-j][i];
      arr[n-1-j][i] = arr[n-1-i][n-1-j];
      arr[n-1-i][n-1-j] = arr[j][n-1-i];
      arr[j][n-1-i] = arr[i][j];
      arr[i][j] = temp;
    }
  }
}
int main(){
  IOS;
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  t{
    
    cin>>n; 
    vvi arr(n,vi(n));
    fin0(i,0,n,1){
      fin0(j,0,n,1){
        cin>>arr[i][j];
      }
    }
    rotate_anti(arr); 
    print(arr);
    cout<<"\n";
    rotate_clock(arr);
    print(arr);
    cout<<"\n";
    rotate_clock(arr);
    print(arr);
    cout<<"\n";
  }
  return 0;
}
