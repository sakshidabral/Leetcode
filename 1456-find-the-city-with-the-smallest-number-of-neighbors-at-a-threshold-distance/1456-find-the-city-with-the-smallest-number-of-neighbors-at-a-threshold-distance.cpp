class Solution {
public:
    #define P pair<int, int>

    int findTheCity(int n, vector<vector<int>>& edges, int dist) {
        vector<vector<int>> grid(n, vector<int>(n, 1e9+7));

        for (int i = 0; i < n; i++) {
            grid[i][i] = 0;  // Distance to itself is zero
        }

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            grid[u][v] = wt;
            grid[v][u] = wt;
        }

        floydWarshall(n, grid);

        return getCityWithFewestReachable(n, grid, dist);
    }

    void floydWarshall(int n, vector<vector<int>>& grid) {
        for(int via = 0; via < n; via++) {
            for(int i = 0; i<n; i++) {
                for(int j = 0; j<n; j++) {
                   grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                }
            }
        }
    }

    int getCityWithFewestReachable(int n, const vector<vector<int>>& grid, int dist) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = INT_MAX;

        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && grid[i][j] <= dist) {
                    reachableCount++;
                }
            }

            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }

};