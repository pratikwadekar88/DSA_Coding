class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        int n = adj.size();
        vector<int> vis(n,0);
        queue<int> que;
        vector<int> ans;
        que.push(0);
        ans.push_back(0);
        vis[0]=1;
        while(!que.empty()){
            int node = que.front();
            que.pop();
            for(int i=0;i<adj[node].size();i++){
                int curr_node = adj[node][i];
                if(!vis[curr_node){
                    ans.push_back(adj[node][i]);
                    que.push(adj[node][i]);
                    vis[adj[node][i]]= 1;
                }
            }
        }
        return ans;
    }
};
