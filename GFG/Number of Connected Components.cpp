class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int row,int col,vector<vector<int>> &vis, vector<vector<char>> &grid){

        queue<pair<int,int>> q;
        q.push({row,col});
        int n=grid.size(),m= grid[0].size();

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            for(int delrow =-1;delrow<=1;delrow++){
                for(int delcol= -1;delcol<= 1;delcol++){
                    int nrow = node.first + delrow;
                    int ncol = node.second + delcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                    && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(),m= grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(i,j,vis,grid);
                    ans++;
                }
            }
        }

    return ans;
    }
};
