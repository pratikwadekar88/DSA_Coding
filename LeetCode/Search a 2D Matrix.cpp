/*You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

*/

class Solution {
public:
    // Approach 2: Binary Search on the entire matrix treated as a 1D array
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();       // Number of rows in the matrix
        int m = matrix[0].size();    // Number of columns in the matrix
        int low = 0, high = m * n - 1; // Initialize pointers for binary search on the "virtual" 1D array

        while (low <= high) {
            int mid = (low + high) / 2;   // Find the middle index in the "virtual" array
            int row = mid / m;            // Convert the middle index to the corresponding row
            int col = mid % m;            // Convert the middle index to the corresponding column
            if (matrix[row][col] == target)
                return true;              // Target found
            if (matrix[row][col] < target)
                low = mid + 1;            // Search in the right half
            else
                high = mid - 1;           // Search in the left half
        }
        return false;                      // Target not found
    }

    // Approach 1: Binary Search first in the column and then in the row
    // Function to perform binary search on a specific column of the matrix
    // int binarySearchColumn(vector<vector<int>>& matrix, int target, int col) {
    //     int low = 0, high = matrix.size() - 1;
    //     while (low <= high) {
    //         int mid = (low + high) / 2;  
    //         if (matrix[mid][col] == target)
    //             return mid;
    //         else if (matrix[mid][col] > target) {
    //             high = mid - 1;
    //         } else {
    //             low = mid + 1;
    //         }
    //     }
    //     return high; 
    // }

    // Function to perform binary search on a specific row of the matrix
    // int binarySearchRow(vector<vector<int>>& matrix, int target, int row) {
    //     int low = 0, high = matrix[0].size() - 1;  
    //     while (low <= high) {
    //         int mid = (low + high) / 2;  
    //         if (matrix[row][mid] == target)
    //             return mid;
    //         else if (matrix[row][mid] > target) {
    //             high = mid - 1;
    //         } else {
    //             low = mid + 1;
    //         }
    //     }
    //     return -1; 
    // }

    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     // First, perform binary search on the first column to find the row
    //     int row = binarySearchColumn(matrix, target, 0);
    //     if (row < 0 || row >= matrix.size()) 
    //         return false;

    //     // Then, perform binary search on the found row
    //     int col = binarySearchRow(matrix, target, row);

    //     if (col != -1 && matrix[row][col] == target) 
    //         return true;
    //     return false;
    // }
};
