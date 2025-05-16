#include<bits/stdc++.h>
int helper(int day, int last, vector<vector<int>> &dp,vector<vector<int>> & points){
    if(day==0){
        int maxi = 0;
        for(int i=0;i<3;i++) if(i!=last) maxi = max(maxi,points[0][i]);
        return maxi;
    }
    if(dp[day][last]!=-1) return dp[day][last];
    int maxi = 0;
    for(int i=0;i<3;i++){
        if(i!=last) maxi = max(maxi,points[day][i] + helper(day-1,i,dp,points));
    }
    return dp[day][last] =maxi;

}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // We need to use 2D Dp here , because we have to maintain 2 states
    // One is index which is day and second is last to maintain which task performed on last day.
    // vector<vector<int>> dp(n+1, vector<int>(4,-1));
    //This is the solution using DP with memoization.
    // return helper(n-1,3,dp,points);

    // Now we will tabulate our solution.
    // dp[0][0] = max(points[0][1],points[0][2]);
    // dp[0][1] = max(points[0][0],points[0][2]);
    // dp[0][2] = max(points[0][1],points[0][0]);
    // dp[0][3] = max(points[0][1],max(points[0][0],points[0][2]));

    // for(int i=1;i<n;i++)
    //     for(int j=0;j<4;j++)
    //         for(int k=0;k<3;k++) if(k!=j) dp[i][j] = max(dp[i][j],points[i][k] +dp[i-1][k]);

    // int ans =0;
    // for(int i=0;i<4;i++) ans = max(ans,dp[n-1][i]);
    // return ans;

    // Above solution requires O(n*4) space.
    // Now we will reduce it to constant space.
    vector<int> prev(4,0);
    prev[0] = max(points[0][1],points[0][2]);
    prev[1] = max(points[0][0],points[0][2]);
    prev[2] = max(points[0][1],points[0][0]);
    prev[3] = max(points[0][1],max(points[0][0],points[0][2]));

    vector<int> curr(4,0);
    for(int i=1;i<n;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<3;k++) if(k!=j) curr[j] = max(curr[j],points[i][k] +prev[k]);
        }
        prev = curr;
    }
    
    return prev[3];



    
}