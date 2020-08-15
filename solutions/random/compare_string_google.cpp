// Problem Statement @: https://leetcode.com/discuss/interview-question/352458/

#include<bits/stdc++.h>
using namespace std;

int calc_min(string x){
        int ans;
        int count[256]={0};
        for(int i=0;i<x.length();i++){
            count[x[i]-'a']++;
        }
        for(int i=0;i<256;i++){
            if(count[i]>0)
            {ans= count[i];
            break;}
        }
        return ans;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> queries_small;
        vector<int> words_small;
       for(auto x: queries){
           queries_small.push_back(calc_min(x));
       } 
        for(auto y: words){
            words_small.push_back(calc_min(y));
        }
        vector<int> ans;
        for(int i=0;i<queries_small.size();i++){
            int count=0;
            for(int j=0;j<words_small.size();j++){
                if(words_small[j]<queries_small[i])
                    ++count;
            }
            ans.push_back(count);
        }
        return ans;
    }
    
int main(){
    string A,B;
    getline(cin,A);
    getline(cin,B);
      vector<int> result;
    vector<string> queries,words;
    string intermediate;
    stringstream A_stream(A);
    stringstream B_stream(B);
    while(getline(A_stream,intermediate,',')){
        words.push_back(intermediate);
    }
    while(getline(B_stream,intermediate,',')){
        queries.push_back(intermediate);
    }
    result= numSmallerByFrequency(queries,words);
    for(auto i:result){
        cout<<i<<" ";
    }
    return 0;
}
