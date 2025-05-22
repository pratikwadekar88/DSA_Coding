class Solution {
public:
    // int helper(int ind, int amount,vector<int> & coins,vector<vector<int>> &dp){
    //     if(amount==0) return 0;
    //     if(ind==0){
    //         if(amount%coins[ind]==0) return amount/coins[ind];
    //         else return 1e9;
    //     }
    //     if(dp[ind][amount]!=-1) return dp[ind][amount];
    //     int skip = helper(ind-1,amount,coins,dp);
    //     int take = (amount>=coins[ind])? 1+ helper(ind,(amount-coins[ind]),coins,dp):1e9;

    //     return dp[ind][amount] = min(skip,take);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        // int ans = helper(n-1,amount,coins,dp);


        // vector<vector<int>> dp(n,vector<int> (amount+1,0));
        // for(int i=0;i<=amount;i++){
        //     if(i%coins[0]==0) dp[0][i] = i/coins[0];
        //     else dp[0][i] = 1e9;
        // }

        // for(int ind=1;ind<n;ind++){
        //     for(int amt=0;amt<=amount;amt++){
        //         int skip = dp[ind-1][amt];
        //         int take = (amt>=coins[ind])? 1+ dp[ind][amt-coins[ind]]:1e9;
        //         dp[ind][amt] = min(skip,take);
        //     }
        // }
        // int ans = dp[n-1][amount];
        // return ans>=1e9?-1:ans;
        vector<int> prev(amount+1,0), curr(amount+1,0);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) prev[i] = i/coins[0];
            else prev[i] = 1e9;
        }

        for(int ind=1;ind<n;ind++){
            for(int amt=0;amt<=amount;amt++){
                int skip = prev[amt];
                int take = (amt>=coins[ind])? 1+ curr[amt-coins[ind]]:1e9;
                curr[amt] = min(skip,take);
            }
            prev = curr;
        }
        int ans = prev[amount];
        return ans>=1e9?-1:ans;
    }
};