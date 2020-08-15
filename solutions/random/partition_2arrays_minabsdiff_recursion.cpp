// Problem Statement @: https://leetcode.com/discuss/interview-question/356433/

#include<bits/stdc++.h>
using namespace std;

int findMinRec(int arr[],int i,int sumCalculated,int sumTotal){
    
    if(i==0){
        return abs((sumTotal-sumCalculated)-sumCalculated);
    }
    return min(findMinRec(arr,i-1,sumCalculated,sumTotal), findMinRec(arr,i-1,sumCalculated+arr[i-1],sumTotal));
}
int findMin(int arr[],int n){
    int sumTotal=0;
    for(int i=0;i<n;i++){
        sumTotal += arr[i];
    }
    return findMinRec(arr,n,0,sumTotal);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findMin(arr,n);
    return 0;
}
