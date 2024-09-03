/*Given a string s, find the length of the longest 
substring
 without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // Initialize two pointers, left and right, both starting at the beginning of the string.
        int left = 0, right = 0;
        
        // Get the length of the input string.
        int n = s.length();
        
        // Variable to keep track of the maximum length of the substring without repeating characters.
        int len = 0;
        
        // Create a vector to store the last seen index of each character.
        // Initialize all elements to -1, indicating that no character has been seen yet.
        vector<int> mpp(256, -1);

        // Traverse the string using the right pointer.
        while(right < n) {
            
            // If the current character has been seen before and its last seen position is within the current window,
            // move the left pointer to the right of the last seen position.
            if(mpp[s[right]] != -1) 
                left = max(mpp[s[right]] + 1, left);

            // Update the last seen index of the current character to the current position (right pointer).
            mpp[s[right]] = right;
            
            // Calculate the length of the current substring and update the maximum length found so far.
            len = max(len, right - left + 1);
            
            // Move the right pointer to expand the window.
            right++;            
        }
        
        // Return the length of the longest substring without repeating characters.
        return len;
    }
};
