int helper(int ind,int w,vector<int> &profit,vector<int> &weight,vector<vector<int>> &dp){
    if(ind==0)return profit[0]*(w/weight[0]);
    if(dp[ind][w]!=-1) return dp[ind][w];
    int skip = helper(ind-1,w,profit,weight,dp);
    int take = weight[ind]<=w?profit[ind] + helper(ind,w-weight[ind],profit,weight,dp):0;

    return dp[ind][w]=max(skip,take);
}

int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    // vector<vector<int>> dp(n,vector<int>(w+1,-1));
    // return helper(n-1,w,profit,weight,dp);

    // vector<vector<int>> dp(n,vector<int>(W+1,0));


    // for(int i=0;i<=W;i++)dp[0][i] = profit[0]*(i/weight[0]);

    // for(int ind=1;ind<n;ind++){
    //     for(int w=0;w<=W;w++){
    //         int skip = dp[ind-1][w];
    //         int take = weight[ind]<=w?profit[ind] + dp[ind][w-weight[ind]]:0;
    //         dp[ind][w]=max(skip,take);
    //     }
    // }

    // return dp[n-1][W];

    vector<int> prev(W+1,0);

    for(int i=0;i<=W;i++)prev[i] = profit[0]*(i/weight[0]);

    for(int ind=1;ind<n;ind++){
        for(int w=0;w<=W;w++){
            int skip = prev[w];
            int take = weight[ind]<=w?profit[ind] + prev[w-weight[ind]]:0;
            prev[w]=max(skip,take);
        }
    }

    return prev[W];
}