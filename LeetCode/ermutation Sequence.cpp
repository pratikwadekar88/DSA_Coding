class Solution {
public:

/*The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

 

Example 1:

Input: n = 3, k = 3
Output: "213"
*/

    // Function to find the k-th permutation sequence of numbers from 1 to n
    string getPermutation(int n, int k) {
        
        // Initialize a list to store numbers from 1 to n
        vector<int> numbers;
        // Variable to store factorial of (n-1)
        int fact = 1;

        // Populate the numbers list and calculate (n-1)!
        for (int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        // Add the nth number to the list
        numbers.push_back(n);
        
        // String to store the final answer
        string ans = "";
        // Convert k to 0-based index
        k = k - 1;

        // Loop to find each digit of the k-th permutation
        while (true) {
            // Determine the index of the next number to add to the permutation
            // k / fact gives the index of the number in the current list
            int index = k / fact;

            // Append the number at the calculated index to the answer string
            ans = ans + to_string(numbers[index]);

            // Remove the used number from the list to avoid repetition
            numbers.erase(numbers.begin() + index);
            
            // If all numbers have been used, exit the loop
            if (numbers.size() == 0)
                break;

            // Update k to find the index for the next position in the permutation
            // k % fact reduces k to the remainder when divided by fact
            k = k % fact;

            // Update fact to be the factorial of the remaining numbers
            // Divide fact by the new size of the numbers list
            fact = fact / numbers.size(); 
        }
        
        // Return the k-th permutation sequence
        return ans;
    }
};
