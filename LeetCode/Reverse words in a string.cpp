class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        
        // Removing leading spaces
        while(i < s.length() && s[i] == ' ') 
            i++;
        s = s.substr(i, s.length());  // Trim starting spaces by creating a new substring

        // Removing trailing spaces
        j = s.length() - 1;
        while(j >= 0 && s[j] == ' ') 
            j--;
        s = s.substr(0, j + 1);  // Trim ending spaces by creating a new substring

        // Removing extra spaces between words
        j = 1;
        while(j < s.length()) {
            if(s[j] == ' ' && s[j - 1] == ' ') 
                s.erase(j, 1);  // Erase the extra space if found
            else 
                j++;
        }
        
        // Reversing each word in the string
        i = 0, j = 0;
        while(j < s.length()) {
            if(s[j] == ' ') {  // When we find a space, reverse the current word
                int start = i, end = j - 1;
                while(start <= end) 
                    swap(s[start++], s[end--]);  // Reverse the characters in the word
                i = j + 1;  // Move to the next word
            }
            j++;
        }

        // Reversing the last word (edge case when the string ends)
        int start = i, end = j - 1;
        while(start <= end) 
            swap(s[start++], s[end--]);  // Reverse the last word

        // Reversing the whole string to get the words in the correct order
        i = 0, j = s.length() - 1;
        while(i <= j) 
            swap(s[i++], s[j--]);  // Reverse the entire string

        return s;  // Return the final reversed words string
    }
};
