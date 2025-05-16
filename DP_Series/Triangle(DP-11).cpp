class Solution {
    public:
        int helper(int i,int j,int n, vector<vector<int>> & t,vector<vector<int>> & dp){
            if(i==n-1) return t[i][j];
            if(j>i) return 0;
            if(dp[i][j]!=-1) return dp[i][j];
            int down = t[i][j] + helper(i+1,j,n,t,dp);
            int diag = t[i][j] + helper(i+1,j+1,n,t,dp);
    
            return dp[i][j] = min(down, diag);
    
        }
        int minimumTotal(vector<vector<int>>& triangle) {
            
            int n = triangle.size();
            // This is solved using DP with memoization.
            // vector<vector<int>> dp(n,vector<int> (n,-1));
            // return helper(0,0,n,triangle,dp);
    
            // Here we have solved using DP tabulation
            // Space complexity is still O(N*N)
            // Here we have saved stack space of N.
    
            // for(int i=0;i<n;i++) dp[n-1][i] = triangle[n-1][i];
    
            // // vector<int> prev(n,0);
            // for(int i= n-2;i>=0;i--){
            //     for(int j=0;j<=i;j++){
            //         int diag = INT_MAX,down =0;
            //         if(j+1<n) diag = dp[i+1][j+1];
            //         dp[i][j] = triangle[i][j] + min (dp[i+1][j],diag);
            //     }
            // }
            // return dp[0][0];
    
    
            // Here we have reduved space complexity to O(N) .
            // Now we are just storing previous row.
    
    
            vector<int> prev = triangle[n-1],curr(n,0);
            for(int i= n-2;i>=0;i--){
                for(int j=0;j<=i;j++){
                    int diag = INT_MAX;
                    if(j+1<n) diag = prev[j+1];
                    curr[j] = triangle[i][j] + min (prev[j],diag);
                }
                prev = curr;
            }
            return prev[0];
    
            
        }
    };