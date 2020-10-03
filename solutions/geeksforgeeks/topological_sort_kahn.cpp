// Problem Statement @: https://practice.geeksforgeeks.org/problems/topological-sort/1

#include <bits/stdc++.h>

using namespace std;

vector <int> topoSort(int N, vector<int> adj[]);

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector <int> res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}// } Driver Code Ends


// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/

// Kahn's algorithm for topological sort
vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    bool visited[V];
    vector<int> res;
    memset(visited, false, sizeof(visited));
    int indegree[V];
    memset(indegree,0, sizeof(indegree));
    for(int i=0 ; i < V;i++)
    {for(auto x: adj[i])
        {
            indegree[x]++;
        }
    }
    queue<int> que;
    for(int i= 0; i< V;i++){
        if(indegree[i]==0)
           que.push(i);
    }
    while(!que.empty()){
        int a= que.front();
        que.pop();
        if(visited[a])
          continue;
        visited[a] = true;
        for(auto x: adj[a])
        {
            indegree[x]--;
            if(indegree[x]==0)
              {
                  que.push(x);
                  }
                  
        }
        res.push_back(a);
    }
    return res;
}
