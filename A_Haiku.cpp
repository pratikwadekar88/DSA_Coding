#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent,size;
    public:
        DisjointSet(int n){
            parent.resize(n+1,0);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++) parent[i] = i;
        }
        int findUPar(int node){
            if(node ==parent[node])
                return node;
            return parent[node]= findUPar(parent[node]);
        }
        void unionBySize(int u,int v){
            int ultp_u = findUPar(u); 
            int ultp_v = findUPar(v);
            if(ultp_u== ultp_v)return;
            if(size[ultp_u]<size[ultp_v]){
                parent[ultp_u] = ultp_v;
                size[ultp_v] += size[ultp_u];
            }else{
                parent[ultp_v] = ultp_u;
                size[ultp_u] += size[ultp_v];
            }
        }
};
#define int ll
#define sz(a) int(a.size())
#define unm unordered_map
#define uns unordered_set

using ll = long long;
typedef long double ld;
using pii = pair<int, int>;
typedef vector<long long> vi;
 
void solve() {

}
 
int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin>>t;cin.clear();
    while(t--) {
        // cout<<solve()<<endl;
        solve();	
    }
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}
