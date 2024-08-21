/*
Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize 'ans' to the smallest possible integer to track the maximum sum found
        int ans = INT_MIN;
        // Initialize 'sum' to accumulate the sum of the current subarray
        int sum = 0;
        
        // Iterate through each element in the input vector
        for (int i = 0; i < nums.size(); i++) {
            // Add the current element to the running sum
            sum += nums[i];
            // Update 'ans' to the maximum value between the current 'ans' and 'sum'
            ans = max(sum, ans);
            // If 'sum' becomes negative, reset it to 0 as a new subarray will start
            if (sum < 0) {
                sum = 0;
            }
        }
        
        // Return the maximum sum of any subarray found
        return ans;
    }
};


