/*Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0; // Initialize counters for two potential majority elements
        int ele1, ele2; // Variables to store the two potential majority elements

        // First pass: Find the two potential majority elements
        for(int i = 0; i < n; i++) {
            if(cnt1 == 0 && ele2 != nums[i]) {
                ele1 = nums[i]; // Assign new candidate for ele1
                cnt1 = 1; // Reset the counter for ele1
            } else if(cnt2 == 0 && ele1 != nums[i]) {
                ele2 = nums[i]; // Assign new candidate for ele2
                cnt2 = 1; // Reset the counter for ele2
            } else if(ele1 == nums[i]) {
                cnt1++; // Increment counter if current element matches ele1
            } else if(ele2 == nums[i]) {
                cnt2++; // Increment counter if current element matches ele2
            } else {
                cnt1--; // Decrement both counters if current element matches neither
                cnt2--;
            }
        }

        // Second pass: Count the occurrences of ele1 and ele2 in the array
        int c1 = 0, c2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == ele1) c1++;
            if(nums[i] == ele2) c2++;
        }

        vector<int> ans; // To store the result
        int mini = int(n / 3) + 1; // Minimum count needed to be a majority element (> n/3)

        // Add ele1 to the result if its count is sufficient
        if(c1 >= mini)
            ans.push_back(ele1);

        // Add ele2 to the result if its count is sufficient and it's different from ele1
        if(c2 >= mini && ele1 != ele2)
            ans.push_back(ele2);

        return ans; // Return the result
    }
};
