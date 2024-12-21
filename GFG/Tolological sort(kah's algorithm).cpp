class Solution {
  public:
    
    bool dfs(int src, vector<int> &vis,vector<vector<int>> &adj,stack<int> &st){
        vis[src] = 1;
        
        for(auto it : adj[src]){
            if(!vis[it])
                dfs(it,vis,adj,st);
        }
        st.push(src);
        
        
    }
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        // int V = adj.size();
        // stack<int> st;
        // vector<int> vis(V,0);
        
        // for(int i=0;i<V;i++){
        //     if(!vis[i])
        //         dfs(i,vis,adj,st);
        // }
        
        // vector<int> ans;
        // while(!st.empty()){
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        
        // return ans;
        
        //This is solved using BFS : Kah's algorithm
        int v = adj.size();
        vector<int> inedges(v,0);
        for(auto it : adj)
            for(auto i: it)
                inedges[i]++;
            
        queue<int> q;
        for(int i=0;i<v;i++) if(inedges[i]==0)q.push(i);
        vector<int> ans;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                inedges[it]--;
                if(inedges[it]==0)
                    q.push(it);
            }
        }
        
        return ans;
    }
};
