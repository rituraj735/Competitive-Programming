#include<bits/stdc++.h>
using namespace std;

int minimumJumps(int[], int);
int main()
{

int t;
cin>>t;
while(t--)
{
int n,i,j;
cin>>n;
int arr[n];
for(int i=0; i<n; i++)
cin>>arr[i];
cout<<minimumJumps(arr, n)<<endl; 
}
return 0;
} }

int minimumJumps(int arr[], int n){
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]= INT_MAX;
    }
    dp[0]= 0;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(j+arr[j] >= i){
                if(dp[j]!=INT_MAX)
                  dp[i] = min(dp[i],1+dp[j]);
            }
        }
    }
    if(dp[n-1]== INT_MAX)
       return -1;
    return dp[n-1];
}
