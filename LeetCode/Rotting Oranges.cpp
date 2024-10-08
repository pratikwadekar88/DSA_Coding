class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); // Number of rows in the grid
        int n = grid[0].size(); // Number of columns in the grid
        int ans = 0; // Variable to track the maximum time taken to rot all oranges

        queue<pair<pair<int, int>, int>> que; // Queue to store the position of rotten oranges and time elapsed

        // Traverse the grid to find all initially rotten oranges (value 2)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    // Push each rotten orange's coordinates along with time (0 initially) into the queue
                    que.push({{i, j}, 0});
                }
            }
        }

        // Arrays to check the four possible directions: left, right, up, down
        int row[] = {0, 0, -1, 1};
        int col[] = {-1, 1, 0, 0};

        // Process the grid using BFS to rot adjacent fresh oranges (value 1)
        while (!que.empty()) {
            auto temp = que.front(); // Get the front element in the queue
            que.pop(); // Remove the processed element from the queue

            ans = max(ans, temp.second); // Update the time taken to rot oranges

            // Check in all four directions (left, right, up, down) for fresh oranges
            for (int i = 0; i < 4; i++) {
                int newi = temp.first.first + row[i]; // Calculate new row position
                int newj = temp.first.second + col[i]; // Calculate new column position

                // Check if the new position is within grid bounds
                if (newi < m && newi >= 0 && newj < n && newj >= 0) {
                    // If a fresh orange is found, rot it and add it to the queue with updated time
                    if (grid[newi][newj] == 1) {
                        grid[newi][newj] = 2; // Mark the fresh orange as rotten
                        que.push({{newi, newj}, temp.second + 1}); // Add the new rotten orange to the queue
                    }
                }
            }
        }

        // After BFS, check if any fresh oranges remain (value 1)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1; // If any fresh orange remains, return -1 (impossible to rot all oranges)
                }
            }
        }

        // Return the maximum time taken to rot all oranges
        return ans;
    }
};
