#include<bits/stdc++.h>
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  /*
    Don't write main().
    Don't read input, it is passed as function argument.    
    No need to print anything.
    Taking input and printing output is handled automatically.
  */
  vector<pair<int,int>> adj[n];
  for(int i=0;i<edges.size();i++){
    adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
  }

  // priority_queue <pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, greater<pair<pair<int,int>,int>>> pq;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  pq.push({0,0});
  vector<int> vis(n,0);
  int sum = 0;
  while(!pq.empty()){
    auto front = pq.top();
    pq.pop();
    int w = front.first;
    int node = front.second;
    if(vis[node]) continue;
    sum+=w;
    vis[node]=1;
    for(auto it:adj[node]){
      int adjNode = it.first;
      int adjNodeWeight = it.second;
      
      if(!vis[adjNode]){
        pq.push({adjNodeWeight,adjNode});
      }

    }
  }
  return sum;
}