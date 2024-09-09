//Greedy

/*You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any order.

 

Example 1:

Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].
*/

class Solution {
public:

    // Comparator function to sort the pairs based on the second element
    // The static keyword ensures this function is bound to the class, not an object
    bool static comp(const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];  // Return true if the second element of 'a' is less than that of 'b'
    }

    // Function to find the longest chain of pairs
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();  // Get the size of the input vector of pairs
        
        // Sort the pairs using the custom comparator, so they are sorted by the second element
        sort(pairs.begin(), pairs.end(), comp);

        int cnt = 1;  // Initialize the count of the longest chain with the first pair
        int lastValue = pairs[0][1];  // Keep track of the last selected pair's second element

        // Loop through the remaining pairs to build the longest chain
        for (int i = 1; i < n; i++) {
            // If the current pair can be chained (start of current pair > end of last pair)
            if (pairs[i][0] > lastValue) {
                cnt++;  // Increment the count of the chain
                lastValue = pairs[i][1];  // Update the lastValue to the end of the current pair
            }
        }

        return cnt;  // Return the length of the longest chain
    }
};
