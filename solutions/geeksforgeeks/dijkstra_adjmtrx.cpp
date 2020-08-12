// Problem statement @: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1/?track=DSASP-Graph&batchId=154

// The adjaceny of the graph is represented as a matrix here, there is an alternative using adjaceny list which is supposed to be easier 

#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(vector<vector<int>> , int ,int );
int printSolution(vector <int> dist, int n)
{
for (int i = 0; i < n; i++)
printf("%d ", dist[i]);
}
int main()
{
  int t;
  int V;
  cin>>t;
  while(t--){
      cin>>V;
      vector<vector<int>> g(V);
      for(int i = 0;i<V;i++){
      vector<int> temp(V);
      g[i] = temp;
      }
    for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
              {
                  cin>>g[i][j];
              }
        }
    int s;
    cin>>s;
    vector <int> res = dijkstra(g, s, V);
    printSolution (res, V);
    cout<<endl;
    }
    return 0;
}

vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    vector<int> dist(V,INT_MAX);
    dist[src]= 0;
    bool processed[V];
    memset(processed,false, sizeof(processed));
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,src));
    while(!pq.empty()){
        int a= pq.top().second;
        pq.pop();
        if(processed[a])
          continue;
        processed[a]=true;
        for(int i=0;i<V;i++){
            if(dist[a]+g[a][i]< dist[i] && g[a][i]!=0){
                dist[i]= dist[a]+ g[a][i];
                pq.push({-dist[i],i});
            }
        }
    }
    return dist;
}

