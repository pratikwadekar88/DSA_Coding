class Solution {
    
  private:
    void dfs(int node, vector<vector<int>> & adj,vector<int> &vis,vector<int> &ans){
        
        vis[node]=1;
        ans.push_back(node);
        
        for(auto it : adj[node]){
            if(!vis[it])
                dfs(it,adj,vis,ans);
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> vis(n,0);
        vector<int> ans;
        int start = 0;
        
        dfs(start,adj,vis, ans);
        return ans;
        
    }
};
