class Solution {
public:
    bool bfs(int u,vector<int> & color,vector<vector<int>>& graph){
        queue<pair<int,int>> q;
        q.push({u,0});
        int n = graph.size();
        color[u] = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto v : graph[node.first]){
                if(color[v]==node.second)return false;
                if(color[v]==-1){
                    color[v] = (node.second+1)%2;
                    q.push({v,color[v]});
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(i,color,graph))
                    return false;
            }
        }
    return true;
    }
};
