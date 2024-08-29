class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // Vector to store the resulting triplets
        vector<vector<int>> ans;
        int n = nums.size();  // Get the size of the input array

        // Sort the array to help in finding triplets and avoid duplicates
        sort(nums.begin(), nums.end());

        // Iterate through the array
        for(int i = 0; i < n; i++) {
            // Skip duplicate elements to avoid duplicate triplets
            if(i != 0 && nums[i] == nums[i - 1]) continue;

            // Initialize two pointers, one just after i and one at the end of the array
            int j = i + 1;
            int k = n - 1;

            // Two-pointer approach to find pairs that sum up with nums[i] to zero
            while(j < k) {
                // Skip duplicate elements to avoid duplicate triplets
                if(j - 1 != i && nums[j] == nums[j - 1]) {
                    j++;
                    continue;
                }
                if(k + 1 != n && nums[k] == nums[k + 1]) {
                    k--;
                    continue;
                }

                // Calculate the sum of the current triplet
                int sum = nums[i] + nums[j] + nums[k];

                // If the sum is zero, we found a valid triplet
                if(sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } 
                // If the sum is less than zero, move the left pointer to the right
                else if(sum < 0) {
                    j++;
                } 
                // If the sum is greater than zero, move the right pointer to the left
                else {
                    k--;
                }
            }
        }

        // Return the result containing all unique triplets that sum to zero
        return ans;
    }
};
