/*Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    
        // // Approach 2: Better Approach (Using Set to Avoid Duplicates)
        // set<vector<int>> st;  // Set to store unique quadruplets

        // int n = nums.size();

        // // Iterate through each pair of elements (i, j)
        // for(int i = 0; i < n; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         set<long long> hset;  // Set to store the required fourth element to form the target sum
        //         for(int k = j + 1; k < n; k++) {
        //             // Calculate the sum of the first three elements
        //             long long sum = nums[i] + nums[j];
        //             sum += nums[k];
        //             // Calculate the fourth element needed to reach the target sum
        //             long long fourth = target - sum;

        //             // If the fourth element is already in the set, we have found a valid quadruplet
        //             if (hset.find(fourth) != hset.end()) {
        //                 vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
        //                 // Sort the quadruplet to avoid permutations of the same set
        //                 sort(temp.begin(), temp.end());
        //                 st.insert(temp);  // Insert the sorted quadruplet into the set
        //             }
        //             // Insert the current element into the set for future reference
        //             hset.insert(nums[k]);
        //         }
        //     }
        // }

        // // Convert the set of unique quadruplets to a vector and return
        // vector<vector<int>> ans(st.begin(), st.end());
        // return ans;


       // Approach 3: Optimal Solution (Two-Pointer Technique)
        vector<vector<int>> ans;

        // Sort the array to make it easier to avoid duplicates and use the two-pointer technique
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // Iterate through the array to fix the first two elements
        for(int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicates for the first element

            for(int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // Skip duplicates for the second element

                int k = j + 1;  // Initialize the third pointer
                int l = n - 1;  // Initialize the fourth pointer

                // Use the two-pointer technique to find the remaining two elements
                while(k < l) {
                    // Calculate the sum of the four elements
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                    
                    // If the sum is less than the target, move the third pointer to the right
                    if(sum < target) k++;
                    // If the sum is greater than the target, move the fourth pointer to the left
                    else if(sum > target) l--;
                    // If the sum equals the target, we found a valid quadruplet
                    else {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++; l--;  // Move both pointers to search for other possibilities
                        // Skip duplicates for the third element
                        while(k < l && nums[k] == nums[k - 1]) k++;
                        // Skip duplicates for the fourth element
                        while(k < l && nums[l] == nums[l + 1]) l--;
                    }
                }
            }
        }

        // Return the result containing all unique quadruplets
        return ans;
    }
};
