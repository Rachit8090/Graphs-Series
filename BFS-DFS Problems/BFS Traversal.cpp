 vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int>q;
        vector<bool>vis(V,false);
        q.push(0);
        vector<int>ans;
        vis[0]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto x:adj[node]){
               if(!vis[x]){
                   vis[x]=true;
                   q.push(x);
               }
            }
        }
        return ans;
    }
