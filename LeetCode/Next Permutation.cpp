/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]


*/



class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Get the size of the input vector
        int n = nums.size();
        
        // Initialize variables for tracking the index to swap and minimum element
        int swap1 = -1;  // This will store the index of the element to be swapped
        int minEle = INT_MAX;  // This will store the minimum element greater than nums[swap1]
        int minInd = -1;  // This will store the index of the minimum element
        
        // Find the largest index 'i' such that nums[i] < nums[i + 1] from last
        // This is the first step in finding the next permutation
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                swap1 = i;  // Record the index where the swap needs to occur
                break;  // Exit the loop once the index is found
            }
        }
        
        // If 'swap1' is found, it means there is a next permutation possible
        if (swap1 != -1) {
            // Find the smallest element greater than nums[swap1] to swap with
            for (int i = swap1 + 1; i < n; i++) {
                if (nums[i] <= minEle && nums[i] > nums[swap1]) {
                    minEle = nums[i];  // Update the minimum element
                    minInd = i;  // Update the index of the minimum element
                }
            }
            // Swap the element at 'swap1' with the found minimum element
            swap(nums[swap1], nums[minInd]);
            // Reverse the sequence from 'swap1 + 1' to the end to get the next permutation
            reverse(nums.begin() + swap1 + 1, nums.end());
        } else {
            // If no such index was found, reverse the entire vector to get the smallest permutation
            reverse(nums.begin(), nums.end());
        }
    }
};
