class Solution {
public:
    int helper(int i,int j1,int j2,vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
        if(j1>=grid[0].size() || j1<0 || j2>=grid[0].size() || j2<0) return -1e8;
        if(i==grid.size()-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int mx = INT_MIN;
        for(int k=-1;k<=1;k++){
            for(int l= -1;l<=1;l++){
                if(j1==j2) mx = max(mx,grid[i][j1] + helper(i+1,j1+k,j2+l,grid,dp));
                else mx = max(mx,grid[i][j1] + grid[i][j2] + helper(i+1,j1+k,j2+l,grid,dp));
            }
        }
        return dp[i][j1][j2] =mx;
        // return mx;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return helper(0,0,m-1,grid,dp);





    }
};