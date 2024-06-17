There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.



void dfs(int node,vector<int>&vis,vector<int>adj[]){
    vis[node]=1;
    for(auto x:adj[node]){
        if(!vis[x]){
            dfs(x,vis,adj);
        }
    }
}
    int findCircleNum(vector<vector<int>>& ad) {
       int n=ad.size();
        int m=ad[0].size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ad[i][j]==1 and i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i);}
            }
        }
        int cnt=0;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,visited,adj);
            }
        }  
        return cnt;   
    }
