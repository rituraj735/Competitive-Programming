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
# define mpp make_pair
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

vector<bool> visited;
	vector<int> tin;
	vector<int> low;
vector<bool> points;
void dfs(int v,vector<vector<int>> &adj,vector<int> &tin,vector<int>&low,int &timer,vector<bool> &visited, int V, vector<bool> &points, int p = -1){
		visited[v] = true;
		tin[v] = low[v] = timer++;
		int children = 0;
		for(auto to : adj[v]){
			if(to == p) continue;
			if(visited[to]) low[v] = min(low[v],tin[to]);
			else{
				dfs(to,adj,tin,low,timer,visited,V,points,v);
				low[v] = min(low[v], low[to]);
				if(low[to] >= tin[v] && p!=-1){
					 points[v] = true;
				}
				++children;
			}
		}
		if(p==-1 && children>1){
			 points[v] = true;
		}
}
void findarti(vector<vector<int>> &adj, int V, int E){
	visited.assign(V,false);
	tin.assign(V,-1);
	low.assign(V,-1);
	points.assign(V,false);
	int timer = 0;
	for(int i=0; i<V; i++){
		if(!visited[i])
			dfs(i,adj,tin,low,timer,visited,V,points);
	}
}
int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
  IOS;
  int cas =0;
  while(true){

  	  cas++;
  	  int V;
  	  cin>>V;

  	  if(!V) break;
      cout<<"\n";
  	  unordered_map<string,int> mp;
  	  vector<string> order(V);
       vector<string> ordered;

  	  string str;
  	  fin0(i,0,V,1){
  	  	cin>>str;
  	  	mp[str] = i;
  	  	order[i] = str;
  	  }
  	  int E;
  	  cin>>E;
  	  vector<vector<int>> adj(V);
	  string source , dest;
  	  while(E--){
  	  	   cin>>source>>dest;
  	  	   adj[mp[source]].push_back(mp[dest]);
  	  	   adj[mp[dest]].push_back(mp[source]);
  	  }
  	  int camera=0;
  	  findarti(adj,V,E);
  	  for(auto x: points)
  	  	 if(x)
  	  	 	camera++;
  	  cout<<"City map #"<<cas<<": "<<camera<<" camera(s) found\n";
  	for(int i=0; i<points.size(); i++) {
  		if(points[i]){
  			ordered.push_back(order[i]);
  		}
  	}
    sort(ordered.begin(),ordered.end());
    for(int i = 0; i<ordered.size();i++){
      cout<<ordered[i]<<"\n";
    }
    
  }
  return 0;

}
