class Solution {
public:
    typedef pair<int,int> p;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto vec : flights){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            adj[u].push_back({v,w});
        }

        queue<pair<int,int>> q;
        q.push({src,0});
        dist[src]=0;

        int steps = 0;

        while(!q.empty() && steps<=k){
            int size = q.size();
            while(size--){
                int u = q.front().first;
                int d = q.front().second;
                q.pop();

                for(auto vec : adj[u]){
                    int node = vec.first;
                    int wt = vec.second;
                    if(d+wt < dist[node]){
                        dist[node] = d+wt;
                        q.push({node, d+wt});
                    }
                }
            }
            steps++;
        }

        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};