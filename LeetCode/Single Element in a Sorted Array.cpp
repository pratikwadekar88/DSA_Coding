/*ou are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10*/


class Solution {
public:
    // Function to find the single non-duplicate element in a sorted array
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        // If there's only one element, return it (since it has no duplicate)
        if(n == 1) return nums[0];
        
        // Check if the first element is the unique one
        if(nums[0] != nums[1]) return nums[0];
        
        // Check if the last element is the unique one
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int low = 1; // Start from the second element
        int high = n - 2; // End at the second last element
        
        // Binary search to find the single non-duplicate element
        while(low <= high) {
            int mid = (low + high) / 2;
            
            // If the mid element is different from both its neighbors, it's the unique one
            if((nums[mid] != nums[mid-1]) && (nums[mid] != nums[mid+1]))
                return nums[mid];
            
            // If mid is even
            if(mid % 2 == 0) {
                // If mid matches with the next element, the unique element is in the right half
                if(nums[mid] == nums[mid+1]) {
                    low = mid + 1;
                } else {
                    // Else, the unique element is in the left half
                    high = mid - 1;
                }
            } 
            // If mid is odd
            else {
                // If mid matches with the previous element, the unique element is in the right half
                if(nums[mid] == nums[mid-1]) {
                    low = mid + 1;
                } else {
                    // Else, the unique element is in the left half
                    high = mid - 1;
                }
            }
        }
        
        // Return -1 if no unique element is found (this case shouldn't happen with valid input)
        return -1;
    }
};
