/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {

        //Approach 1
        /*Here we can simply use any sorting algorithm
        and sort the elements
        It will takr O(NlogN) time*/

        //Approach 2
        //Count no of 0's ,1's and 2' and overwrite the array

        //Approach 3
        //Dutch National flag algorithm. 

        // Initialize pointers
        int mid = 0; // This pointer will traverse the array
        int low = 0; // This pointer will track the position of the next 0
        int high = nums.size() - 1; // This pointer will track the position of the next 2

        // Iterate until mid pointer crosses the high pointer
        while (mid <= high) {
            if (nums[mid] == 0) {
                // Case when the current element is 0
                // Swap it with the element at the low pointer
                swap(nums[mid], nums[low]);
                // Increment both mid and low pointers since 0 is in its correct position
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                // Case when the current element is 1
                // No swapping needed since 1 should remain in the middle
                // Just move the mid pointer ahead
                mid++;
            } else {
                // Case when the current element is 2
                // Swap it with the element at the high pointer
                swap(nums[mid], nums[high]);
                // Decrement the high pointer since 2 is in its correct position
                // Don't increment mid here because the swapped element at mid needs to be checked
                high--;
            }
        }
        return; // Return after sorting is complete
    }
};
