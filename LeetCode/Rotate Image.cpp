/*You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();   // Get the number of rows in the matrix
        int m = matrix[0].size(); // Get the number of columns in the matrix

        // First, reverse each column by swapping elements from top to bottom
        for (int i = 0; i < m; i++) {
            int j = 0, k = n - 1; // j starts from the top, k starts from the bottom
            while (j <= k) {
                // Swap the elements in the current column between the top and bottom
                swap(matrix[j++][i], matrix[k--][i]);
            }
        }

        // Second, transpose the matrix by swapping elements across the diagonal
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // Swap elements across the diagonal to transpose the matrix
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
