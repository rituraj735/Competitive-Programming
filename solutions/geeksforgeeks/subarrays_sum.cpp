// Problem Statement @: https://practice.geeksforgeeks.org/problems/subarray-range-with-given-sum2804/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int subArraySum(int arr[], int n, int sum)
    {
    	int curr_sum = 0;
    	int count = 0;
    	unordered_map<int,int> mp;
    	for(int i=0 ; i<n ; i++){
    	    curr_sum += arr[i];
    	    
    	   if(curr_sum == sum)
    	       count++;
    	    if(mp.find(curr_sum - sum) != mp.end()){
    	         count += mp[curr_sum-sum];
    	    }
    	    mp[curr_sum]++;
    	}
    	return count;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,sum=0;
        cin>>n;
        int arr[n];
        for(int i=0; i<n;i++)
        cin>>arr[i];
        cin>>sum;
        Solution ob;
        cout<<ob.subArraySum(arr,n,sum);
        cout<<'\n';
    }
    return 0;
}
