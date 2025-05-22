class Solution {
public:
    int helper(int ind, int amt,vector<int> & coins,vector<vector<int>> &dp){
        if(ind==0){
            if(amt%coins[0]) return 0;
            else return 1;
        }
        // if(ind<0) return amt==0;
        if(dp[ind][amt]!=-1) return dp[ind][amt];
        int skip = helper(ind-1,amt, coins,dp);
        int take = (amt>=coins[ind])? helper(ind,amt-coins[ind],coins,dp):0;
        return dp[ind][amt] =skip + take; 
    }
    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        
        // vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        // return helper(coins.size()-1,amount,coins,dp);

        // vector<vector<long long>> dp(n,vector<long long> (amount+1,0));

        // for(int i =0;i<=amount;i++)if(i%coins[0]==0) dp[0][i] = 1;

        // for(int ind=1;ind<n;ind++){
        //     for(int amt=0;amt<=amount;amt++){
        //         int skip = dp[ind-1][amt];
        //         int take = coins[ind]<=amt?dp[ind][amt-coins[ind]]:0;
        //         dp[ind][amt] = (long long)skip + take;
        //     }
        // }

        // return (int)dp[n-1][amount];
        vector<long long> curr(amount+1,0),prev(amount+1,0);

        for(int i =0;i<=amount;i++)if(i%coins[0]==0) prev[i] = 1;

        for(int ind=1;ind<n;ind++){
            for(int amt=0;amt<=amount;amt++){
                int skip = prev[amt];
                int take = coins[ind]<=amt?curr[amt-coins[ind]]:0;
                curr[amt] = (long long)skip + take;
            }
            prev=curr;
        }

        return (int)prev[amount];
    
    }
};