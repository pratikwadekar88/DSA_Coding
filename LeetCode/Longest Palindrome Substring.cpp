class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length(); // Get the length of the string
        vector<vector<int>> dp(n, vector<int>(n)); // Create a DP table to store palindrome checks
        int maxLen = 1; // Variable to store the maximum palindrome length, initially 1 (single character)
        int start = 0; // Start index of the longest palindrome substring
        int end = 0;   // End index of the longest palindrome substring

        // Initialize DP table for substrings of length 1 (each character is a palindrome)
        for(int i = 0; i < n; i++) dp[i][i] = 1;

        // Check for palindromes of length 2
        for(int i = 1; i < n; i++) {
            if(s[i-1] == s[i]) { // If two consecutive characters are equal
                dp[i-1][i] = 1;  // Mark as palindrome in DP table
                maxLen = 2;      // Update max length to 2
                start = i-1;     // Update start index
                end = i;         // Update end index
            }
        }

        // Check for palindromes of length 3 and more
        for(int len = 3; len <= n; len++) {
            for(int i = 0; i + len <= n; i++) {
                int j = i + len - 1; // End index of the substring
                
                // If characters at the start and end are equal and the substring between them is a palindrome
                if(s[i] == s[j] && dp[i+1][j-1] == 1) {
                    dp[i][j] = 1;  // Mark as palindrome in DP table
                    
                    // If the current palindrome is longer than the previously found one
                    if((j - i + 1) > maxLen) {
                        start = i;      // Update start index
                        end = j;        // Update end index
                        maxLen = j - i + 1; // Update max length
                    }
                }
            }
        }

        // Return the longest palindrome substring
        return s.substr(start, end - start + 1);
    }
};
