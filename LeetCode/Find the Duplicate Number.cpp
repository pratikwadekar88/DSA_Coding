/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Initialize two pointers, both starting from the first element of the array
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Detecting the cycle
        do {
            slow = nums[slow];          // Move slow pointer one step
            fast = nums[nums[fast]];    // Move fast pointer two steps
        } while (slow != fast);          // Continue until they meet

        // Phase 2: Finding the entrance to the cycle (the duplicate number)
        fast = nums[0];  // Reset fast to the start of the array
        while (slow != fast) {   // Move both one step at a time
            slow = nums[slow];
            fast = nums[fast];
        }
        // Return the duplicate number
        return fast;
    }
};
