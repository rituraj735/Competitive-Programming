//Problem statement @: https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1/?track=DSASP-Graph&batchId=154

#include<bits/stdc++.h>
using namespace std;

void dfs_stk(int u,stack<int> &st,vector<int> adj[], int V,bool visited[]){
    visited[u]=true;
    for(auto v:adj[u]){
        if(visited[v]){
        
            continue;
        }
        visited[v]=true;
        dfs_stk(v,st,adj,V,visited);
         
    }
    st.push(u);
}

void dfs(int u,vector<int> adj[], int V,bool processed[]){
    processed[u]=true;
    for(auto v:adj[u]){
        if(processed[v])
          continue;
        processed[v]=true;
        dfs(v,adj,V,processed);
    }
}

int kosaraju(int V, vector<int> adj[])
{
  stack<int> st;
  bool visited[V];
  memset(visited,false,sizeof(visited));
  for(int i=0;i<V;i++){
      if(!visited[i])
         dfs_stk(i,st,adj,V,visited);
  }
  vector<int> transpose[V];
  for(int i=0;i<V;i++){
       for(auto x:adj[i]){
           transpose[x].push_back(i);
       }
  }
  int count=0;
  bool processed[V];
  memset(processed,false,sizeof(processed));
  while(!st.empty()){
      int a= st.top();
      st.pop();
      if(!processed[a]){
          dfs(a,transpose,V,processed);
           count++;
      }
  }
  return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
          int a, b;
          cin >> a >> b;
          int m, n;
          vector<int> adj[a];
          for (int i = 0; i < b; i++) {
                    cin >> m >> n;
                    adj[m].push_back(n);
                  }
          cout << kosaraju(a, adj) << endl;
          }
          return 0;
          }
