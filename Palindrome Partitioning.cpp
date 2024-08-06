class Solution {
public:
    /*
    Given a string s, partition s such that every 
    substring of the partition is a palindrome.
    Return all possible palindrome partitioning of s.

    Example 1:
    Input: s = "aab"
    Output: [["a","a","b"],["aa","b"]]
    */

    // Function to check if a given substring is a palindrome
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--])
                return false; // Return false if characters don't match
        }
        return true; // Return true if the substring is a palindrome
    }

    // Recursive function to generate all possible palindrome partitions
    void generate(string s, vector<vector<string>> &ans, vector<string> &ds, int ind) {
        // Base condition: when we reach the end of the string
        if (ind == s.length()) {
            ans.push_back(ds); // Add the current partition to the answer
            return;
        }
        for (int i = ind; i < s.length(); ++i) {
            // Check if the current substring is a palindrome
            if (isPalindrome(s, ind, i)) {
                ds.push_back(s.substr(ind, i - ind + 1)); // Add the substring to the current partition
                generate(s, ans, ds, i + 1); // Recursively generate partitions for the rest of the string
                ds.pop_back(); // Backtrack to explore other partitions
            }
        }
    }

    // Main function to initiate the partitioning process
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans; // To store the final partitions
        vector<string> ds; // To store the current partition
        generate(s, ans, ds, 0); // Start the recursive generation
        return ans; // Return the result
    }
};
