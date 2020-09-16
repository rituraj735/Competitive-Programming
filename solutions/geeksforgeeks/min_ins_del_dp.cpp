// Problem Statement @: https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions/0
#include<bits/stdc++.h>
using namespace std;

class Solution{
		public:
            int minOperations(string str1, string str2) 
             { 
                int n1 = str1.size();
                int n2 = str2.size();
                int lcs[n1+1][n2+1];
                for(int i=1;i<=n2;i++)
                    lcs[0][i]= 0;
                for(int i=1;i<=n1;i++)
                    lcs[i][0]= 0;
                lcs[0][0]= 0;

                for(int i=1;i<=n1;i++){
                    for(int j=1;j<=n2;j++){
                        if(str1[i-1]==str2[j-1])
                            lcs[i][j]= 1+lcs[i-1][j-1];
                        else{
                            lcs[i][j]= max(lcs[i-1][j], lcs[i][j-1]);
                        }
                    }
                }
               return n1 + n2 - (2*lcs[n1][n2]); 
            } 
};

int main()
{
      int t;
      cin >> t;
      while (t--)
      {
          string s1, s2;
          cin >> s1 >> s2;
          Solution ob;
          cout << ob.minOperations(s1, s2) << "\n";
      }
      return 0;
}

  
