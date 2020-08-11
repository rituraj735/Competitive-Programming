//Problem statement @: https://practice.geeksforgeeks.org/problems/detect-cycle-using-dsu/1/?track=DSASP-DisjointSet&batchId=154
#include<bits/stdc++.h>
using namespace std;

int
findRoot (int a, int parent[])
{
  if (a == parent[a])
    return a;
  parent[a] = findRoot (parent[a], parent);
  return parent[a];
}

void
union_a (int a, int b, int parent[], int rank1[])
{
  int x = findRoot (a, parent);
  int y = findRoot (b, parent);
  if (x == y)
    return;
  else if (rank1[x] < rank1[y])
    parent[x] = y;
  else if (rank1[y] < rank1[x])
    parent[y] = x;
  else
    {
      parent[y] = x;
      rank1[x]++;
    }

}

bool
findCycle (vector < int >adj[], int parent[], int rank1[], int n, int e)
{
  bool visited[n + 1];
  memset (visited, false, sizeof (visited));
  for (int i = 1; i <= n; i++)
    {
      if (visited[i])
	continue;
      visited[i] = true;
    for (auto x:adj[i])
	{
	  if (visited[x])
	    continue;
	  else if (findRoot (x, parent) == findRoot (i, parent))
	    return true;
	  else
	    {
	      union_a (x, i, parent, rank1);
	    }
	}
    }
  return false;
}

int
main ()
{
  int t;
  cin >> t;
  while (t--)
    {
      int n, e;
      cin >> n >> e;
      vector < int >adj[n + 1];
      int parent[n + 1];
      int rank1[n + 1];
      for (int i = 0; i < e; i++)
	{
	  int u, v;
	  cin >> u >> v;
	  adj[u].push_back (v);
	  adj[v].push_back (u);
	}

      for (int i = 1; i <= n; i++)
	{
	  parent[i] = i;
	  rank1[i] = 1;
	}
      if (findCycle (adj, parent, rank1, n, e))
	{
	  cout << "1";
	}
      else
	cout << "0";
      cout << endl;
    }
  return 0;
}
