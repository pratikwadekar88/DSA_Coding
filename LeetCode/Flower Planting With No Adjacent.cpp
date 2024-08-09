class Solution {
public:

/*You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes a bidirectional path between garden xi to garden yi. In each garden, you want to plant one of 4 types of flowers.

All gardens have at most 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th garden. The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists.

 

Example 1:

Input: n = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Explanation:
Gardens 1 and 2 have different types.
Gardens 2 and 3 have different types.
Gardens 3 and 1 have different types.
Hence, [1,2,3] is a valid answer. Other valid answers include [1,2,4], [1,4,2], and [3,2,1].*/
    // Function to check if assigning the given flower to the garden is safe
    bool isSafe(int flower, vector<int> &flowers, int garden, vector<vector<int>> &adj) {
        // Iterate through all adjacent gardens
        for (int i = 0; i < adj[garden].size(); i++) {
            // If any adjacent garden has the same flower, it's not safe to plant
            if (flowers[adj[garden][i] - 1] == flower)
                return false;
        }
        // If no adjacent garden has the same flower, it's safe to plant
        return true;
    }

    // Recursive function to assign flowers to gardens
    bool solve(vector<vector<int>> &adj, int garden, vector<int> &flowers, int n) {
        // Base case: If all gardens have been processed, return true
        if (garden > n)
            return true;

        // Try assigning each flower (1 to 4) to the current garden
        for (int i = 1; i <= 4; i++) {
            // Check if assigning flower 'i' is safe for the current garden
            if (isSafe(i, flowers, garden, adj)) {
                // Assign the flower to the garden
                flowers[garden - 1] = i;
                // Recurse to assign flowers to the next garden
                if (solve(adj, garden + 1, flowers, n))
                    return true;
                // If assigning flower 'i' didn't work, backtrack
                flowers[garden - 1] = 0;
            }
        }
        // If no valid flower assignment is found, return false
        return false;
    }

    // Main function to generate the flower assignment for all gardens
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        // Create an adjacency list to represent the garden connections
        vector<vector<int>> adj(n + 1);
        for (auto i : paths) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        // Initialize the flowers vector with 0s (indicating no flower assigned yet)
        vector<int> flowers(n);

        // Print the initial state of the flowers vector (all should be 0)
        for (auto i : flowers) cout << i << " ";

        // Start assigning flowers from garden 1
        solve(adj, 1, flowers, n);

        // Prepare the result vector to return the final flower assignments
        vector<int> ans;
        for (auto i : flowers) ans.push_back(i);

        // Return the result
        return ans;
    }
};
