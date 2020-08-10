#include<bits/stdc++.h>
using namespace std;

int find(int x,int par[]){
if(x == par[x])
return x;
par[x] = find(par[x],par);
return par[x];
}
void union_( int a, int b, int par[], int rank1[]) {
int x = find(a,par);
int y = find(b,par);
if(x==y)
return;
if(rank1[x] < rank1[y])
par[x] = y;
else if(rank1[x] > rank1[y])
par[y] = x;
else{
par[y] = x;
rank1[x]++;
}
}

bool isConnected(int x,int y, int par[], int rank1[]) {
return (find(x,par) == find(y,par));
}

int main(){
   int t;
   cin>>t;
   while(t--){
      int n;
      cin>>n;
      int par[n+1];
      int rank[n+1];
      for(int i=1;i<=n;i++){
         par[i]=i;
         rank1[i]=1;
         }
       int q;
       cin>>q;
       while(q--){
         int a,b;
         char c;
         cin>>c>>a>>b;
         if(c=='U')
            union(a,b,par,rank1);
         else 
           cout<<isConnected(a,b,par,rank1)<<endl;
         }
         }
         return 0;
        }
