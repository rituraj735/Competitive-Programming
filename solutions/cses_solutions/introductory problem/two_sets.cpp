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
  ll n;
  cin>>n;
  if(((1LL* n) * (n+1)) % 4){
    cout<<"NO";
    exit(0);
  }
  else{
  ll req_sum = ((1LL* n) * (n+1))/4;

  ll arr[n];
  fin0(i,0,n,1){
    arr[i]= i+1;
  }
  vll x;
  ll lptr=0, rptr= n-1;
  ll sum=0;
  while(sum!=req_sum){
     if(arr[lptr]+arr[rptr]< (req_sum - sum))
         {
             x.pb(arr[lptr]);
             x.pb(arr[rptr]);
             sum += arr[lptr]+ arr[rptr];
             lptr++; rptr--;
         }
     else if(arr[lptr]+arr[rptr]== (req_sum-sum))
        {
             x.pb(arr[lptr]);
             x.pb(arr[rptr]);
             sum += arr[lptr]+ arr[rptr];
         }
     else if(arr[lptr]+ arr[rptr]> (req_sum-sum))
     {
         rptr--;
     }
  }
  cout<<"YES\n"<<x.size()<<"\n";
  sort(all(x));
  ll a=x.size();
  fin0(i,0,a,1)
     cout<<x[i]<<" ";
  cout<<"\n";
  cout<<n-a<<"\n";
  ll px=0;
  string y;
  fin1(i,1,n,1){
    if(x[px]==i){
            px++;
        continue;
    }
    else{
        y += to_string(i)+" ";
    }
    }
    cout<<y;
  }
  return 0;
}
