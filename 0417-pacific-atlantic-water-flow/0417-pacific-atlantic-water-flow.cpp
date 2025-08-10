class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> ans;

        vector<vector<bool>> pac(m, vector<bool>(n));
        vector<vector<bool>> atl(m, vector<bool>(n));

        // we will start with those cells which are already connected to oceans
        for(int i=0; i<m; i++){
            dfs(heights, pac, i, 0, -1, -1); // first col
            dfs(heights, atl, i, n-1, -1, -1); // last col
        }

        for(int j=0; j<n; j++){
            dfs(heights, pac, 0, j, -1, -1); // first row
            dfs(heights, atl, m-1, j, -1, -1); // last row
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int i, int j, int ni, int nj){
        if(i < 0 || i == heights.size() || j < 0 || j == heights[0].size() || vis[i][j]){
            return;
        }
        if(ni >= 0 && nj >= 0 && heights[i][j] < heights[ni][nj]){
            return;
        }

        vis[i][j] = true;
        dfs(heights, vis, i-1, j, i, j);
        dfs(heights, vis, i+1, j, i, j);
        dfs(heights, vis, i, j-1, i, j);
        dfs(heights, vis, i, j+1, i, j);
    }
};