class Solution {
  public:
    void toposort(int src,stack<int> &st,vector<int> &vis,vector<vector<int>> &adj){
        vis[src] =1;
        for(int it : adj[src]){
            if(!vis[it])
                toposort(it,st,vis,adj);
        }
        st.push(src);
    }
    vector<vector<int>> transpose(vector<vector<int>> &adj){
        vector<vector<int>> tp(adj.size());
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                tp[adj[i][j]].push_back(i);
            }
        }
        return tp;
    }
    void dfs(int src,vector<int> &vis,vector<vector<int>> &adj){
        vis[src] =1;
        for(int it : adj[src]){
            if(!vis[it])
                dfs(it,vis,adj);
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        // code here 
        
        //To Solve this problem there are three main important steps.
        //1.Fist use topological sort algorithm to get a stack.
        //2.Transpose the adjcancy list i.e reverse the edges.
        //3.Pop one by one element from the stack and apply dfs.
        //The no. of times you apply dfs those number of strongly connected components you have.
        int n = adj.size();
        vector<int> vis(n,0);
        stack<int> st;
        int ans =0;
        
        for(int i=0;i<n;i++) if(!vis[i]) toposort(i,st,vis,adj);
        vector<vector<int>> tp = transpose(adj);
        vector<int> vis2(n,0);
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis2[node]){
                ans++;
                dfs(node,vis2,tp);
            }
        }
        return ans;
        
    }
}:
