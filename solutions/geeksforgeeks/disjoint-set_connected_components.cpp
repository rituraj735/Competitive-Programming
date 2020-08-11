#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int rank1[100001];

int findRoot(int x, int arr[]){
    if(x==arr[x])
      return x;
    arr[x]= findRoot(arr[x],arr);
    return arr[x];
}

void unionNodes( int a, int b, int arr[], int rank1[], int n) {
       int x= findRoot(a,arr);
       int y= findRoot(b,arr);
       if(x==y)
         return ;
       else if(rank1[x]<rank1[y]) arr[x]= y;
       else if(rank1[y]<rank1[x]) arr[y]= x;
       else{
           arr[x]=y;
           rank1[y]++;
       }
}

int findNumberOfConnectedNodes( int n, int arr[], int rank1[]) {
    int count =0;
    for(int i=1;i<=n;i++){
        if(arr[i]==i)
          count++;
    }
    return count;
}

int main() {
int t;
cin>>t;
while(t--) {
int n;
cin>>n;
for(int i=1; i<=n; i++) {
arr[i] = i;
rank1[i] = 1;
}
int q;
cin>>q;
while(q--) {
int a,b;
cin>>a>>b;
unionNodes(a,b, arr, rank1, n);
}
cout<<findNumberOfConnectedNodes(n, arr, rank1)<<endl;
}
return 0;
}
