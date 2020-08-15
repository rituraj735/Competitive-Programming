// Problem Statement @: https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/

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
        sort(words_small.begin(), words_small.end());
        vector<int> ans;
        for(int i=0;i<queries_small.size();i++){
            int count=0;
            for(int j=0;j<words_small.size();j++){
                if(words_small[j]>queries_small[i])
                    ++count;
            }
            ans.push_back(count);
        }
        return ans;
    }
