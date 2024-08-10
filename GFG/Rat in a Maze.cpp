/*Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the destination at (n - 1, n - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list. The driver will output "-1" automatically.

Examples:

Input: mat[][] = [[1, 0, 0, 0],
                [1, 1, 0, 1], 
                [1, 1, 0, 0],
                [0, 1, 1, 1]]
Output: DDRDRR DRDDRR
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
*/
    void solve(int i, int j, vector<vector<int>> &mat, vector<string> &ans, string move, vector<vector<bool>> &vis, int n, int di[], int dj[]) {
    // Base case: if we reach the bottom-right corner (destination)
    if (i == n - 1 && j == n - 1) {
        ans.push_back(move); // Add the current path to the answer list
        return;
    }

    // Simplified approach using direction vectors
    string dir = "DLRU"; // D=Down, L=Left, R=Right, U=Up
    for (int k = 0; k < 4; k++) { // Loop over all possible directions
        int nexti = i + di[k]; // Calculate the next row index
        int nextj = j + dj[k]; // Calculate the next column index

        // Check if the next cell is within bounds, unvisited, and open (mat[nexti][nextj] == 1)
        if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && mat[nexti][nextj] == 1) {
            vis[i][j] = true; // Mark the current cell as visited
            solve(nexti, nextj, mat, ans, move + dir[k], vis, n, di, dj); // Recursively explore the next cell
            vis[i][j] = false; // Backtrack by unmarking the current cell as visited
        }
    }
}

vector<string> findPath(vector<vector<int>> &mat) {
    int n = mat[0].size(); // Size of the matrix (assuming square matrix)
    vector<string> ans; // To store all possible paths
    int di[] = {+1, 0, 0, -1}; // Direction vector for rows (Down, Left, Right, Up)
    int dj[] = {0, -1, +1, 0}; // Direction vector for columns (Down, Left, Right, Up)
    vector<vector<bool>> vis(n, vector<bool>(n, false)); // Visited matrix to keep track of visited cells

    // Start the search from the top-left corner if it's open
    if (mat[0][0] == 1) {
        solve(0, 0, mat, ans, "", vis, n, di, dj);
    }

    return ans; // Return all found paths
}
