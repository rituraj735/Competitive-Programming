...
...

....
....
....
  // takes input till n and m are being entered and neither n nor m is 0
  while(cin>>n>>m, !(n==0 && m==0)){   
  int from , to;
  vii adj(n);
  for(int i=0; i<m; i++){
  	cin>>from>>to;
  	adj[--from].pb(--to);
  } 
  topological(adj,n,m);
  fin0(i,0,n,1){
  	cout<<++order[i]<<" ";
  }
  cout<<"\n";
  
  }
  return 0;
}
....
..
....
....
