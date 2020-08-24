// Problem Statement @: https://atcoder.jp/contests/abc176/tasks/abc176_d

#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int h,w;
  cin>>h>>w;
  int ch,cw,dh,dw;
  cin>>ch>>cw;

  --ch;
  --cw;
  cin>>dh>>dw;

  --dh;
  --dw;
  vector<string> maze(h);
  for(int i=0;i<h;i++){
     cin>>maze[i];
   }

  auto inside= [&](int i, int j){
        return i>=0 && i<h && j>=0 && j<w && maze[i][j]=='.';
  };

  vector<vector<int>> dist(h,vector<int>(w,INT_MAX));
  dist[ch][cw]=0;
  deque<pair<int,int>> que;
  que.emplace_back(make_pair(ch,cw));
  while(!que.empty()){
    auto [i,j]= que.front();
    que.pop_front();

    for(int x= i-2; x<= i+2 ; x++){
        for(int y= j-2; y<= j+2; y++){
            if(inside(x,y)){
                int warp= ((abs(x-i)+ abs(y-j)) != 1);
                int d= dist[i][j]+warp;
                if(d<dist[x][y]){
                    dist[x][y]= d;

                    if(warp)
                        que.emplace_back(make_pair(x,y));
                    else
                        que.emplace_front(make_pair(x,y));
                }
            }
        }
    }
  }
  int ans= dist[dh][dw];
  if(ans==INT_MAX) ans= -1;
  cout<<ans<<endl;
  return 0;
}
