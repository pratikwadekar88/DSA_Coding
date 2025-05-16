class Solution {
    public:
    
        int helper(int n,vector<int> &nums,vector<int>&dp){
            if(n==0) return nums[0];
            if(n<0) return 0;
            if(dp[n]!=-1) return dp[n];
            //Pick or not pick.
            return dp[n] = max(nums[n] + helper(n-2,nums,dp),helper(n-1,nums,dp));
            
        }
        int rob(vector<int>& nums) {
    
            //This is solved using Memoization.
            // vector<int>dp(nums.size(),-1);
            // return helper(nums.size()-1,nums,dp);
    
    
            // Now we will solve using tabulation.
            if(nums.size()==0) return 0;
            if(nums.size()==1)return nums[0];
            
            // dp[0] = nums[0];
            // for(int i=1;i<nums.size();i++){ 
            //     if(i>1) dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
            //     else dp[i] = max(nums[i],dp[i-1]);
    
            // }
            // return dp[nums.size()-1];
    
            // Now we will minimize the space complexity.
            int prev =0, prev2= nums[0],ans  = INT_MIN;
            for(int i=1;i<nums.size();i++){ 
                ans = max(nums[i]+prev,prev2);
                prev = prev2;
                prev2 = ans;
    
            }
            return ans;
             
        }
    };