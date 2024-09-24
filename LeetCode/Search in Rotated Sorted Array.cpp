/*There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/
class Solution {
public:
    // Function to search for a target in a rotated sorted array
    int search(vector<int>& nums, int target) {
        
        int low = 0;
        int high = nums.size() - 1;
        
        // Binary search loop
        while (low <= high) {
            int mid = (low + high) / 2; // Calculate the mid index
            
            // If target is found at mid, return its index
            if (nums[mid] == target)
                return mid;
            
            // Check if the left half is sorted
            if (nums[mid] >= nums[low]) {
                // If the target is within the sorted left half
                if (nums[mid] >= target && nums[low] <= target) {
                    high = mid - 1; // Narrow down search to the left half
                } else {
                    low = mid + 1; // Otherwise, search the right half
                }
            } 
            // If the right half is sorted
            else {
                // If the target is within the sorted right half
                if (nums[mid] <= target && nums[high] >= target) {
                    low = mid + 1; // Narrow down search to the right half
                } else {
                    high = mid - 1; // Otherwise, search the left half
                }
            }
        }
        
        // Return -1 if target is not found in the array
        return -1;
    }
};
