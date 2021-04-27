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

int cycle_start , cycle_end;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;

bool dfs(int v, int par){
	visited[v] = true;
	for(int u : adj[v]){
		if(u == par) continue;
		if(visited[u]){
			cycle_start = u;
			cycle_end = v;
			return true;
		}
		parent[u] = v;
		if(dfs(u,parent[u]))
			return true;
	}
	return false;
}

void find_cycle(int n){
	vector<int> ans;
	visited.assign(n,false);
	parent.assign(n,-1);
	cycle_start = -1;
	for(int i=0; i<n; i++) {
		if(!visited[i] && dfs(i,parent[i]))
			break;
	}
	if(cycle_start == -1){
		cout<<"IMPOSSIBLE\n";
	}
	else{
		ans.push_back(cycle_start);
		for(int j= cycle_end; j!=cycle_start; j = parent[j]){
			ans.push_back(j);
		}
		ans.push_back(cycle_start);
		reverse(ans.begin(),ans.end());
		cout<<ans.size()<<"\n";
		for(auto x: ans){
			cout<<x+1<<" ";
		}
		cout<<"\n";
	}
}
int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("Downloads/test_input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
  IOS;
  int v, e;
  cin>>v>>e;
  
  int from, to;
  adj.assign(v,vector<int>());
  fin0(i,0,e,1){
  	cin>>from>>to;
  	--from, --to;
  	adj[from].push_back(to);
  	adj[to].push_back(from);
  }
  find_cycle(v);

  return 0;

}
