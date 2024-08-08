// Function to check if it's safe to color a node with a given color
bool isSafe(int node, bool graph[101][101], int col, int n, int color[]) {
    // Iterate over all nodes to check if any adjacent node has the same color
    for(int k = 0; k < n; k++) {
        // Check if k is not the current node, k is adjacent to the current node,
        // and k is already colored with the same color 'col'
        if(k != node && graph[k][node] == 1 && color[k] == col)
            return false; // If all conditions are true, it's not safe to color
    }
    return true; // Safe to color the current node with color 'col'
}

// Recursive function to solve the graph coloring problem
bool solve(bool graph[101][101], int m, int n, int node, int color[]) {
    // Base case: If all nodes have been colored, return true
    if(node == n) {
        return true;
    }
    
    // Try to color the current node with one of the m available colors
    for(int i = 1; i <= m; i++) {
        // Check if it's safe to color the current node with color 'i'
        if(isSafe(node, graph, i, n, color) == true) {
            color[node] = i; // Assign color 'i' to the current node
            
            // Recursively call solve to color the next node
            if(solve(graph, m, n, node + 1, color) == true)
                return true; // If coloring the next node is successful, return true
            
            // Backtrack: If the current coloring does not lead to a solution,
            // reset the color of the current node
            color[node] = 0;
        }
    }
    return false; // If no color can be assigned to this node, return false
}

// Main function to check if a graph can be colored with at most m colors
bool graphColoring(bool graph[101][101], int m, int n) {
    int color[n] = {0}; // Array to store the color assigned to each node, initialized to 0
    
    // Start coloring from the first node (node 0)
    if(solve(graph, m, n, 0, color))
        return true; // If a solution is found, return true
    
    return false; // If no solution is found, return false
}
