// Problem statement @: https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1/?track=DSASP-Graph&batchId=154

#include <bits/stdc++.h>
using namespace std;
bool isBridge(list<int> adj[], int V, int u, int v);

int main() {
int T;
cin >> T;
while (T--) {
int s, N;
cin >> s >> N;
list<int> *adj = new list<int>[s];
for (int i = 0; i < N; i++) {
int u, v;
cin >> u >> v;
adj[u].push_back (v);
adj[v].push_back (u);
}
int a, b;
cin >> a >> b;
if (isBridge(adj, s, a, b))
cout << 1 << endl;
else
cout << 0 << endl;
}
}
 
 
void dfs(int s,list<int> adj[],bool vis[],int V){
    vis[s]=true;
    for(auto x:adj[s]){
        if(vis[x])
          continue;
        vis[x]=true;
        dfs(x,adj,vis,V);
    }
}

bool isBridge(list<int> adj[], int V, int s, int e) {
    adj[s].remove(e);
    adj[e].remove(s);
    bool vis[V];
    memset(vis,false,sizeof(vis));
    for(int i=0;i<V;i++){
        if(!vis[i])
           dfs(s,adj,vis,V);
    }
    if(!vis[e])
      return true;
    return false;
}
