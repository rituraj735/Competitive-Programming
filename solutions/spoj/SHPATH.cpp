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
#define vii vector<vector<int>>         
#define vpi vector<vector<pair<int,int>>>        
const ll INF= 1e18;
vector<int> d;


int djikstra(vpi adj, int source , int dest, int V){
    d.assign(V,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> prior;
    d[source] = 0;
    prior.push({0,source});
    // cout<<"v "<<v<<"dest "<<dest;
    while(!prior.empty()){
        int weight = prior.top().first;
        int v = prior.top().second;
        // cout<<"v "<<v<<"weight "<<weight;
        prior.pop();
        if(v== dest)
            return d[v];
        for(auto edge : adj[v]){
        int to = edge.first;
        int cost = edge.second;
        // cout<<"d[v] "<<d[v]<<" ";
        if(d[v]+cost < d[to]){
            d[to] = d[v]+cost; 
            // cout<<"p "<<to<<" "<<"dist "<<d[to]<<" ";
            prior.push({d[to],to});
        }
    }

    }
    return d[dest];
   
}
int main(){
  IOS;
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  t{
    int V;
    cin>>V;
    int nodes =0;
    vpi adj(V);
    unordered_map<string, int> mp;
    while(nodes < V){
        string city;
        cin>>city;
        mp[city] = nodes;
        int m; cin>>m;
        while(m--){
            int to , weight;
            cin>>to>>weight;
            --to;
            adj[nodes].pb({to,weight});
        }
        nodes++;
    }
    int queries;
    cin>>queries;
    string source, dest;
    while(queries--){
    cin>>source>>dest;
    int i_sou = mp[source], i_des = mp[dest];
    // cout<<i_sou<<" "<<i_des<<" ways ";
    cout<<djikstra(adj,i_sou,i_des,V)<<"\n";
   }
  }
  return 0;

}
