class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        
        // Get the lengths of both strings
        int len1 = str1.length(), len2 = str2.length();
        int i = 0, j = 0;

        // Iterate through both strings
        while (i < len1 && j < len2) {
            // Calculate the next character in cyclic order
            char ch = (str1[i] - 'a' + 1) % 26 + 'a';

            // Check if the current character of str1 matches the current character of str2
            // or if the cyclic next character matches
            if (str1[i] == str2[j] || ch == str2[j]) {
                i++; // Move to the next character in str1
                j++; // Move to the next character in str2
            } else {
                i++; // Only move to the next character in str1
            }
        }

        // If all characters of str2 are matched, return true
        if (j == len2) return true;

        // Otherwise, return false
        return false;
    }
};
