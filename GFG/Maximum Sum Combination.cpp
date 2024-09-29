class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // Sort both arrays A and B in descending order to maximize the combinations
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());
        
        // Set to keep track of already visited index pairs (i,j)
        set<pair<int, int>> st;
        
        // Max-heap (priority queue) to store the sums along with the index pairs
        // The heap stores pairs of (sum, (i, j)) where sum = A[i] + B[j]
        priority_queue<pair<int, pair<int, int>>> pq;
        
        // Start by pushing the largest possible sum (A[0] + B[0]) and its indices (0, 0)
        pq.push({A[0] + B[0], {0, 0}});
        st.insert({0, 0}); // Mark the index pair (0, 0) as visited
        
        // Vector to store the final results
        vector<int> ans;
        
        // Loop K times to extract the K largest sums
        while (K--) {
            // Get the current largest sum and its corresponding indices
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int sum = pq.top().first;
            
            // Add the current largest sum to the result vector
            ans.push_back(sum);
            
            // Remove the current sum from the priority queue
            pq.pop();
            
            // Check the next combination with the same x but y incremented by 1 (A[x] + B[y+1])
            if (y + 1 < N && st.find({x, y + 1}) == st.end()) {
                pq.push({A[x] + B[y + 1], {x, y + 1}});
                st.insert({x, y + 1}); // Mark the index pair (x, y+1) as visited
            }
            
            // Check the next combination with the same y but x incremented by 1 (A[x+1] + B[y])
            if (x + 1 < N && st.find({x + 1, y}) == st.end()) {
                pq.push({A[x + 1] + B[y], {x + 1, y}});
                st.insert({x + 1, y}); // Mark the index pair (x+1, y) as visited
            }
        }
        
        // Return the vector containing the K largest sums
        return ans;
    }
};
