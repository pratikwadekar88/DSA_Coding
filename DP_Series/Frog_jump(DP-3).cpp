#include <bits/stdc++.h> 

int helper(int n,vector<int>& h,vector<int> & dp){
    if(n==0) return 0;
    if(n==1) return abs(h[1]-h[0]);

    if(dp[n]!=-1) return dp[n];

    return dp[n] = min(helper(n-1,h,dp)+abs(h[n-1]-h[n]),helper(n-2,h,dp)+abs(h[n]-h[n-2]));
}
int frogJump(int n, vector<int> &heights)
{
    // This is recursive dp solution.This is solved using memoization.
    // vector<int> dp(n+1,-1);
    // return helper(n-1,heights,dp);

    //This is solved using tabulation.
    vector<int> dp(n,-1);
    dp[0] = 0;
    dp[1] = abs(heights[1]-heights[0]);

    for(int i=2;i<n;i++) dp[i] = min(dp[i-1]+abs(heights[i]-heights[i-1]), dp[i-2]+ abs(heights[i]-heights[i-2]));

    return dp[n-1];

}