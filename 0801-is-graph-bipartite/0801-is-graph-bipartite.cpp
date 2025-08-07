class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i=0; i<n ;i++){
            if(color[i] == -1){
                if(dfs(graph, i, color, 0) == false){
                    return false;
                }
            }
        }

        return true;
    }

    bool dfs(vector<vector<int>>& graph, int u, vector<int>& color, int currColor){
        if(color[u] != -1){
            return color[u] == currColor;
        }

        color[u] = currColor;

        for(int v : graph[u]){
            if(dfs(graph, v, color, 1 - currColor) == false){
                return false;
            }
        }

        return true;
    }
};