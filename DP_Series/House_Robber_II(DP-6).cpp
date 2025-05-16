class Solution {
    public:
        int rob(vector<int>& nums) {
            
            // This is the solution from House Robber question.
            // Here we are first calculating max by excluding
            // first element and then last element so that there never become
            // adjcant.
            if(nums.size()==0) return 0;
            if(nums.size()==1)return nums[0];
            if(nums.size()==2)return max(nums[0],nums[1]);
            int prev =0, prev2= nums[0],ans1  = 0,ans2  = 0;
            for(int i=1;i<nums.size()-1;i++){ 
                ans1 = max(nums[i]+prev,prev2);
                prev = prev2;
                prev2 = ans1;
            }
            prev =0, prev2= nums[1];
            for(int i=2;i<nums.size();i++){ 
                ans2 = max(nums[i]+prev,prev2);
                prev = prev2;
                prev2 = ans2;
    
            }
    
            return max(ans1,ans2);
        }
    };