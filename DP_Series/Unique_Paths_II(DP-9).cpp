class Solution {
    public:
        int helper(int up,int left,vector<vector<int>> & dp,vector<vector<int>>& obstacleGrid){
            if(obstacleGrid[up][left]==1) return 0;
            if(up==0 && left==0)return 1;
            if(dp[up][left]!=-1) return dp[up][left];
            int u= 0,l=0;
            if(up>0) u = helper(up-1,left,dp,obstacleGrid);
            if(left>0) l = helper(up,left-1,dp,obstacleGrid);
            return dp[up][left] = u+l;
        }
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size(),n = obstacleGrid[0].size();
            vector<vector<int>> dp(m,vector<int> (n,-1));
            // return helper(n-1,m-1,dp,obstacleGrid);
    
    
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(obstacleGrid[i][j]==1){
                        dp[i][j] = 0;
                        continue;
                    }
                    if(i==0 && j==0) dp[0][0] = 1;
                    else{
                        int up=0,left=0;
                        if(i-1>=0) up = dp[i-1][j];
                        if(j-1>=0) left = dp[i][j-1];
                        dp[i][j] = up + left;
                    }
                }
            }
            return dp[m-1][n-1];
        }
    };