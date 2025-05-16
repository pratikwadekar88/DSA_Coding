class Solution {
    public:
    
        int helper(int up,int left,vector<vector<int>> & dp){
            if(up==0 && left==0)return 1;
            if(dp[up][left]!=-1) return dp[up][left];
            int u= 0,l=0;
            if(up>0) u = helper(up-1,left,dp);
            if(left>0) l = helper(up,left-1,dp);
            return dp[up][left] = u+l;
        }
        int uniquePaths(int m, int n) {
    
            // This is for normal recursive solution.
            // return helper(m-1,n-1);
    
            //This is solved using DP with memoization.
            vector<vector<int>> dp(m,vector<int>(n,0));
            // return helper(m-1,n-1,dp);
    
            // Now we will tabulate our solution.
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
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
    
            // We can also optimize space here.
            // We will use a array of size  n to store prev row and int prev to store prev
            //element in the row
    
    
        }
    };