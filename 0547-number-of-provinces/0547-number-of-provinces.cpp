class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        int count = 0;
        vector<bool> vis(n, false);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                count++;
                dfs(adj, i, vis);
            }
        }

        return count;
    }

    void dfs(vector<vector<int>>& adj, int u, vector<bool>& vis){
        vis[u] = true;

        for(int v = 0; v < adj.size(); v++){
            if(adj[u][v] == 1 && !vis[v]){
                dfs(adj, v, vis);
            }
        }
    }
};