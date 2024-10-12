class Solution {
public:

    // Recursive function to convert string to integer
    int recursiveFun(string s, int ind, int sign, int n, long long ans = 0){
        // Base case: If we reach the end of the string or the current character is not a digit
        if(ind == n || (s[ind] < '0' || s[ind] > '9'))
            return ans; // Return the calculated answer so far

        int digit = s[ind] - '0'; // Convert the character to its numeric value

        // Check for overflow: if the number is positive and adding the next digit exceeds INT_MAX
        if(sign == 0 && (ans * 10 + digit) >= INT_MAX) return INT_MAX;

        // Check for underflow: if the number is negative and subtracting the next digit exceeds INT_MIN
        if(sign == 1 && (ans * 10 - digit) <= INT_MIN) return INT_MIN;

        // If the number is positive, add the digit to the result
        if(sign == 0) ans = ans * 10 + digit;

        // If the number is negative, subtract the digit from the result
        if(sign == 1) ans = ans * 10 - digit;
        
        // Recursively process the next character in the string
        return recursiveFun(s, ind + 1, sign, n, ans);
    }

    int myAtoi(string s) {
        
        int n = s.length();
        int i = 0;
        int sign = 0; // Default is positive (sign == 0)
        
        // Skip leading whitespace
        while(i < n && s[i] == ' ')
            i++;
        
        // Remove the leading whitespaces from the string
        s = s.substr(i, n);
        
        // Check if the first character indicates a negative number
        if(s[0] == '-'){
            sign = 1; // Set sign to negative
            s = s.substr(1, n); // Remove the negative sign from the string
        } else if(s[0] == '+') {
            s = s.substr(1, n); // Remove the positive sign from the string
        }

        // Call the recursive function to convert the string to an integer
        return recursiveFun(s, 0, sign, s.length(), 0);
    }
};
