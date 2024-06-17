void dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&ans){
      vis[node]=1;
      ans.push_back(node);
      for(auto x:adj[node]){
          if(!vis[x]){
              dfs(x,adj,vis,ans);
          }
      }
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,ans);
            }
        }
        return ans;
    }
