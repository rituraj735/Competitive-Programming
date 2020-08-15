// Problem Statement @: https://leetcode.com/discuss/interview-question/421787/

#include<bits/stdc++.h>
using namespace std;

string mostBooked(vector<string> input){
    unordered_map<string, int> mp;
    for(string str: input){
        if(str[0]=='+')
           mp[str]++;
    }
    int max= INT_MIN;
    string temp;
    for(auto x:mp){
        if(x.second>max){
            max= x.second;
            temp= x.first;
        }
    }
    return string(temp.begin()+1,temp.end());
}

int main(){
    vector<string> input;
    string to_put;
    while(cin>>to_put){
        input.push_back(to_put);
    }
    cout<<mostBooked(input);
    return 0;
}
