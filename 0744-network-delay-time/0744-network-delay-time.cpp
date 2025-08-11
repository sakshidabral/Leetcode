class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;

        for(auto& vec : times){
            int u = vec[0], v = vec[1], w = vec[2];
            adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> res(n + 1, INT_MAX);

        res[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();

            for(auto& [adjNode, wt] : adj[node]){
                if(d + wt < res[adjNode]){
                    res[adjNode] = d + wt;
                    pq.push({d+wt, adjNode});
                }
            }
        }

        int ans = INT_MIN;
        for(int i=1; i<=n; i++){
            if(res[i] == INT_MAX){
                return -1;
            }
            ans = max(ans, res[i]);
        }

        return ans; 
    }
};