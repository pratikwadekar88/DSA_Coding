class Solution {
public:
    /*
    Write a program to solve a Sudoku puzzle by filling the empty cells.

    A sudoku solution must satisfy all of the following rules:

    Each of the digits 1-9 must occur exactly once in each row.
    Each of the digits 1-9 must occur exactly once in each column.
    Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
    The '.' character indicates empty cells.
    */

    // Function to check if placing 'c' at board[row][col] is valid
    bool isValid(vector<vector<char>> &board, int row, int col, char c) {
        // Iterate over each cell in the row, column, and 3x3 sub-box

        for (int i = 0; i < 9; i++) {
            // Check the row for duplicates
            if (board[row][i] == c)
                return false;
            // Check the column for duplicates
            if (board[i][col] == c)
                return false;
            // Check the 3x3 sub-box for duplicates
            //This is the important part because we are accessing 3x3 matrix inside sudoku
            //3 * (row / 3) + (i / 3) -> as i will increase ,it will increase row number when we traverse 3 col in one row
            //3 * (col / 3) + (i % 3) -> This will go go thr columns
            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c)
                return false;
        }
        return true; // If no duplicates found, the placement is valid
    }

    // Recursive function to solve the Sudoku puzzle
    bool solve(vector<vector<char>> &board) {
        // Iterate over each cell in the board each time when we call the function
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // If the cell is empty ('.'), try to place a digit
                if (board[i][j] == '.') {
                    // Try placing digits '1' to '9'
                    for (char c = '1'; c <= '9'; c++) {
                        // Check if placing 'c' is valid
                        if (isValid(board, i, j, c) == true) {
                            // Place the digit 'c'
                            board[i][j] = c;
                            // Recur to solve the rest of the board
                            if (solve(board) == true)//return true if placement is valid
                                return true;
                            else
                                board[i][j] = '.'; // Backtrack if the placement does not lead to a solution
                        }
                    }
                    return false; // Return false if no valid placement found for the current cell
                }
            }
        }
        return true; // Return true if the entire board is solved 
    }

    // Function to solve the Sudoku puzzle
    void solveSudoku(vector<vector<char>>& board) {
        solve(board); // Call the recursive solve function
    }
};
