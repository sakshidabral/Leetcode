class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<vector<int>> adj;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int d = abs(x1 - x2) + abs(y1 - y2);

                adj.push_back({i, j, d});
            }
        }

        sort(adj.begin(), adj.end(), [](vector<int>&a, vector<int>& b){
            return a[2] < b[2];
        });

        vector<int> parent(n), rank(n, 0);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        int sum = 0;
        for(auto& edge : adj){
            int u = edge[0], v = edge[1], w = edge[2];

            int up = find(u, parent);
            int vp = find(v, parent);

            if(up != vp){
                unite(up, vp, parent, rank);
                sum += w;
            }
        }

        return sum;
    }

    int find (int x, vector<int>& parent) {
        if (x == parent[x]) 
            return x;
    
        return parent[x] = find(parent[x], parent);
    }
    
    void unite(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);
    
        if (x_parent == y_parent) 
            return;
    
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
};