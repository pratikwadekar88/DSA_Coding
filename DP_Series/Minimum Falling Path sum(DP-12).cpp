class Solution {
    public:
        // This is starting from front(top down)
        int helper(int i, int j,int n,vector<vector<int>> & matrix,vector<vector<int>> &dp){
            if(j>=n || j<0) return INT_MAX;
            if(i==n-1) return matrix[i][j];
            if(dp[i][j]!= INT_MIN) return dp[i][j];
            return dp[i][j] = matrix[i][j] + min(helper(i+1,j-1,n,matrix,dp),min(helper(i+1,j,n,matrix,dp),helper(i+1,j+1,n,matrix,dp)));
    
        }
        // This is starting from last index(bottom up approach)
        int helper2(int i,int j,vector<vector<int>> & m, vector<vector<int>> & dp){
            if(j>=m.size() || j<0) return INT_MAX;
            if(i==0) return m[i][j];
            if(dp[i][j]!=INT_MIN) return dp[i][j];
            return dp[i][j] = m[i][j] + min(helper2(i-1,j-1,m,dp),min(helper2(i-1,j,m,dp),helper2(i-1,j+1,m,dp)));
        }
        int minFallingPathSum(vector<vector<int>>& matrix) {
            
            int mn = INT_MAX,n = matrix.size();
            // Dp with memoization.
            // vector<vector<int>> dp(n, vector<int> (n,INT_MIN));
            // for(int i=0;i<n;i++) mn = min(mn,helper2(n-1,i,matrix,dp));
            // return mn;
    
            // Tabulated above solution.Saved stack space.
            // dp[0] = matrix[0];
            // for(int i=1;i<n;i++){
            //     for(int j=0;j<n;j++){
            //         int leftDiag  = INT_MAX, up = INT_MAX, rightDiag = INT_MAX;
            //         if(j>0) leftDiag = dp[i-1][j-1];
            //         if(j+1<n) rightDiag = dp[i-1][j+1];
            //         up = dp[i-1][j];
            //         dp[i][j] = matrix[i][j] + min(up,min(leftDiag,rightDiag));
            //     }
            // }
            // for(int it : dp[n-1]) mn = min(mn,it);
            // return mn;
    
            // Here we have reduced space from O(N*N) to O(N).
            vector<int> prev = matrix[0], curr(n,0);
            for(int i=1;i<n;i++){
                for(int j=0;j<n;j++){
                    int leftDiag  = INT_MAX, up = INT_MAX, rightDiag = INT_MAX;
                    if(j>0) leftDiag = prev[j-1];
                    if(j+1<n) rightDiag = prev[j+1];
                    up = prev[j];
                    curr[j] = matrix[i][j] + min(up,min(leftDiag,rightDiag));
                }
                prev = curr;
            }
            for(int it : prev) mn = min(mn, it);
            return mn;
    
    
        }
        
    };