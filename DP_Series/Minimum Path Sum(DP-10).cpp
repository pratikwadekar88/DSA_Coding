class Solution {
    public:
        int helper(int up,int left,vector<vector<int>> &grid,vector<vector<int>> & dp){
            if(up==0 && left==0) return grid[0][0];
    
            if(dp[up][left]!=-1) return dp[up][left];
            int u =INT_MAX, l= INT_MAX;
            if(up>0) u = helper(up-1,left,grid,dp);
            if(left>0) l = helper(up, left-1,grid,dp);
    
            return dp[up][left] = grid[up][left] + min(u,l);
        }
        int minPathSum(vector<vector<int>>& grid) {
            int m = grid.size(), n = grid[0].size();
            vector<vector<int>> dp(m, vector<int> (n,-1));
            // This is using DP with memoization.
            // return helper(m-1,n-1,grid,dp);
    
            // Now we are tabulating above solution.
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i==0 && j==0) dp[0][0] = grid[0][0];
                    else{
                        int up=INT_MAX,left=INT_MAX;
                        if(i-1>=0) up = dp[i-1][j];
                        if(j-1>=0) left = dp[i][j-1];
                        dp[i][j] = grid[i][j] + min(up,left);
                    }
                }
            }
            return dp[m-1][n-1];
        }
    };