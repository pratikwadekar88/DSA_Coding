// https://www.naukri.com/code360/problems/minimal-cost_8180930?leftPanelTabValue=PROBLEM
int helper(int ind , int k, vector<int> &h,vector<int> &dp){

    if(ind==0)return 0;
    if(dp[ind]!=-1) return dp[ind];
    int ans = INT_MAX;
    for(int j=1;j<=k && ind-j>=0;j++) ans = min(ans,helper(ind-j,k,h,dp)+abs(h[ind]-h[ind-j]));
    return dp[ind] = ans;

}
int minimizeCost(int n, int k, vector<int> &height){

    vector<int> dp(n,-1);
    //Solution Using Memoization.
    // return helper(n-1,k,height,dp);

    //Solution using Tabulation
    dp[0] =0;
    for(int i=1;i<n;i++){
        int ans = INT_MAX;
        for(int j=1;j<=k && i-j>=0;j++) ans = min(ans,dp[i-j]+abs(height[i-j]-height[i]));
        dp[i] = ans;
    }
    return dp[n-1];
}