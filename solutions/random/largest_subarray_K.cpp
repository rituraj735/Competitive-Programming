// Problem Statement @: https://leetcode.com/discuss/interview-question/352459/

#include<bits/stdc++.h>
using namespace std;

vector<int> find_subarray(vector<int> array,int n,int k){
         vector<vector<int>> vec;
         for(int i=0;i<n-k+1;i++){
             vector<int> temp;
             for(int j=i;j<i+k;j++){
                 temp.push_back(array[j]);
             }
             vec.push_back(temp);
         }
    sort(vec.begin(),vec.end());
    return vec[vec.size()-1];
}

int main(){
    vector<int> array;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        array.push_back(temp);
    }
    vector<int> result;
    result = find_subarray(array,n,k);
    for(auto i: result){
        cout<<i<<" ";
    }
    return 0;
}
