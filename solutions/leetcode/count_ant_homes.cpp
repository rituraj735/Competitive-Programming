int mod = 1000000007;
    int binpow(long long a, int b, int m ){
        a %= m;
        int res = 1;
        while(b>0){
            if(b &1)
                res = (res%m * a%m )%m;
            a = (a%m * a%m) %m;
            b >>=1 ;
        }
        return res;
    }
    int inv_mod(int deno , int m){
        return binpow(deno,m-2,m);
    }
    int dfs(vector<vector<int>> nextRooms, int size[], int curr){
        int ans = 1;
        for(auto y:nextRooms[curr]){
            ans += dfs(nextRooms,size,y);
        }
        size[curr] = ans;
        return ans;
    }
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();
        vector<vector<int>> nextRooms(n);
        for(int i=1; i<n; i++){
            nextRooms[prevRoom[i]].push_back(i);
        }
        // for(auto p: nextRooms){
            // for(auto q: p)
                  // cout<<q<<" ";
        // }
        // cout<<"\n";
        int size[n];
        dfs(nextRooms, size,0);
        // for(auto p: size){
            // cout<<p<<" ";
        // }
        // cout<<"\n";
        long long fact[n+1];
        fact[0]= fact[1] = 1;
        for(int i =2; i<=n; i++){
            fact[i] = (fact[i-1]*i)%mod;
        }
        // for(auto p: fact){
            // cout<<p<<" ";
        // }
        // cout<<"\n";
         long long deno = 1;
        for(auto y: size){
            deno = (deno * y)%mod;
        }
        int d = (int) deno;
        // cout<<d<<"\n";
        int invMod = inv_mod(d,mod);
        return (int)((fact[n]*invMod)%mod);
    }
