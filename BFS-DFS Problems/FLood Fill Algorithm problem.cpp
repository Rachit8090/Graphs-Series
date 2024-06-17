An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. 
Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

Approach -> BFS Traversal

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>ans=image;
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        q.push({sr,sc});
        vis[sr][sc]=1;
        ans[sr][sc]=color;

        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int nr=i+delrow[k];
                int nc=j+delcol[k];

                if(nr>=0 and nr<=n-1 and nc>=0 and nc<=m-1 and !vis[nr][nc] and image[nr][nc]==image[i][j]){
                    vis[nr][nc]=1;
                    ans[nr][nc]=color;
                    q.push({nr,nc});
                }
            }
        }
        return ans;

    }
