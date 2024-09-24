/*Median in a row-wise sorted Matrix
Difficulty: HardAccuracy: 55.05%Submissions: 118K+Points: 8
Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives 
us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. */

class Solution {   
public:

    // Function to find the first index where the element is greater than n
    int upperBound(vector<int> &arr, int n) {
        int low = 0;
        int high = arr.size() - 1;
        int ans = arr.size(); // Initialize answer as size of array (beyond the last index)
        
        // Binary search to find the upper bound
        while (low <= high) {
            int mid = (low + high) / 2; // Calculate the middle index
            
            // If the middle element is less than or equal to n, search the right half
            if (arr[mid] <= n) {
                low = mid + 1;
            } else {
                // If the middle element is greater than n, search the left half
                ans = mid;
                high = mid - 1;
            }
        }    
        
        return ans; // Return the upper bound index
    }

    // Function to count the number of elements less than or equal to n in a matrix
    int elements(vector<vector<int>> &mat, int n, int R) {
        int cnt = 0;
        // Loop through each row of the matrix
        for (int i = 0; i < R; i++) {
            // Get the upper bound of n in the current row
            int ub = upperBound(mat[i], n);
            // Add the count of elements less than or equal to n
            cnt += ub;
        }
        return cnt;
    }
    
    // Function to find the median of a row-wise sorted matrix
    int median(vector<vector<int>> &matrix, int R, int C) {
        // Initialize the minimum and maximum values of the matrix
        int mn = INT_MAX;
        int mx = INT_MIN;
        
        // Find the minimum element from the first column and maximum element from the last column
        for (int i = 0; i < R; i++) {
            mn = min(mn, matrix[i][0]);
            mx = max(mx, matrix[i][C-1]);
        }
        
        int low = mn;
        int high = mx;
        int x = (R * C) / 2; // The target position of the median element
        
        // Binary search to find the median value
        while (low <= high) {
            int mid = (low + high) / 2;
            
            // Check how many elements in the matrix are less than or equal to mid
            if (elements(matrix, mid, R) <= x) {
                low = mid + 1; // Search the upper half
            } else {
                high = mid - 1; // Search the lower half
            }
        }
        
        return low; // The median value
    }
};
