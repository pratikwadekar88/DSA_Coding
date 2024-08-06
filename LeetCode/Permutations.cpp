class Solution {
public:
/*Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]*/

//This is Approach 2 where we dont use extra space
//Time Complexity will O(n!*n)
void helper(vector<int> &nums, vector<vector<int>> &ans, int ind) {
    // Base condition: if the current index is equal to the size of nums
    if (ind == nums.size()) {
        ans.push_back(nums); // Add the current permutation to the answer
        return;
    }
    // Iterate through each number starting from the current index
    for (int i = ind; i < nums.size(); i++) {
        // Swap the current index with the i-th index
        //it starts from ind index
        swap(nums[ind], nums[i]);
        // Recursively generate permutations for the next index
        helper(nums, ans, ind + 1);
        // Backtrack: undo the swap to restore the original order
        swap(nums[ind], nums[i]);       
    }
}

};


// This the Approach 1 for this problem using O(n) extra space 
//Here we are using an vector to keep record of which element is already taken
/*
class Solution {
public:
    // Helper function to generate permutations
    void helper(vector<int> &nums, vector<vector<int>> &ans, vector<bool> &map, vector<int> &ds) {
        // Base condition: if the current permutation is complete
        if (ds.size() == nums.size()) {
            ans.push_back(ds); // Add the current permutation to the answer
            return;
        }
        // Iterate through each number in nums
        for (int i = 0; i < nums.size(); i++) {
            // If the number is not yet used in the current permutation
            if (map[i] == false) {
                ds.push_back(nums[i]); // Add the number to the current permutation
                map[i] = true; // Mark the number as used
                helper(nums, ans, map, ds); // Recursively generate permutations with the remaining numbers
                map[i] = false; // Backtrack: unmark the number
                ds.pop_back(); // Backtrack: remove the number from the current permutation
            }
        }
    }

    // Main function to generate all permutations of nums
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans; // To store all permutations
        vector<bool> map(nums.size()); // To track which numbers are used in the current permutation
        vector<int> ds; // To store the current permutation

        // Initialize the map to false, indicating no numbers are used yet
        for (int i = 0; i < nums.size(); i++) map[i] = false;

        // Start generating permutations
        helper(nums, ans, map, ds);

        // Return all generated permutations
        return ans;
    }
};
*/
