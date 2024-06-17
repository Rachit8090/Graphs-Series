You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Approach -> BFS Traversal

  int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cntFresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                    
                }
                else if(grid[i][j]==1){cntFresh++;}
            }
        }
        int time=0;
        int cnt=0;
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};

        while(!q.empty()){
            int t=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;

            q.pop();
            time=max(time,t);
            for(int k=0;k<4;k++){
                int nr=i+delrow[k];
                int nc=j+delcol[k];

                if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc]==1 and  !vis[nr][nc]){
                    q.push({t+1,{nr,nc}});
                    vis[nr][nc]=1;
                    cnt++;
                }
            }
        }
        if(cntFresh!=cnt)return -1;
        return time;

Time Complexity: O ( n x n ) x 4    

Reason: Worst-case - We will be making each fresh orange rotten in the grid and for each rotten orange will check in 4 directions

Space Complexity: O ( n x n )
