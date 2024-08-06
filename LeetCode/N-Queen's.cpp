class Solution {
public:

/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.*/
    // Helper function to solve the N-Queens problem using backtracking
    void helper(vector<vector<string>> &ans, vector<string> &board, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int col, int n) {
        if (col == n) {
            ans.push_back(board); // Base condition: if all columns are filled, add the current board configuration to the answer
            return;
        }

        for (int row = 0; row < n; row++) { // Loop through each row in the current column
            // Check if the current position is safe
            if (leftRow[row] == 0 && upperDiagonal[(n - 1) + col - row] == 0 && lowerDiagonal[row + col] == 0) {
                // Place the queen
                leftRow[row] = 1;
                upperDiagonal[(n - 1) + col - row] = 1;
                lowerDiagonal[row + col] = 1;
                board[row][col] = 'Q';

                // Recur to place queens in the next column
                helper(ans, board, leftRow, upperDiagonal, lowerDiagonal, col + 1, n);

                // Backtrack: remove the queen and reset the markers
                leftRow[row] = 0;
                upperDiagonal[(n - 1) + col - row] = 0;
                lowerDiagonal[row + col] = 0;
                board[row][col] = '.';
            }
        }
    }

    // Main function to solve the N-Queens problem
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; // To store all solutions
        vector<string> board(n, string(n, '.')); // Initialize the board with empty cells
        vector<int> leftRow(n, 0); // Track which rows have queens
        vector<int> upperDiagonal(2 * n - 1, 0); // Track which upper diagonals have queens
        vector<int> lowerDiagonal(2 * n - 1, 0); // Track which lower diagonals have queens

        // Start generating solutions from column 0
        helper(ans, board, leftRow, upperDiagonal, lowerDiagonal, 0, n);

        return ans; // Return all generated solutions
    }
};
