#include <bits/stdc++.h>
using namespace std;

bool bellman(int src,vector<pair<long long,pair<int,int>>> edges,int n,int m){
       long long dist[n];
       for(int i=0;i<n;i++){
           dist[i]= INT_MAX;
       }
       dist[src]=0;
       for(int count=0; count<n-1;count++){
           for(auto x: edges){
               int a= x.second.first;
               int b= x.second.second;
               int w= x.first;
               if(dist[b]> dist[a]+w)
                  dist[b]= dist[a]+w;
           }
       }
      for(auto x:edges){
               int a= x.second.first;
               int b= x.second.second;
               int w= x.first;
               if(dist[b]> dist[a]+w)
                  return true;
           }
    return false;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<pair<long long,pair<int,int>>> edges;
        while(m--){
            int u,v;long long weight;
            cin>>u>>v>>weight;
            edges.push_back(make_pair(weight,make_pair(u,v)));
        }
        int src=0;
        if(bellman(src,edges,n,m)){
            cout<<1<<"\n";
        }
        else 
           cout<<0<<"\n";
    }
	return 0;
}
