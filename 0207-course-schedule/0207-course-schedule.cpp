class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<bool> vis(n, false);

        vector<vector<int>> adj(n);
        for(auto vec : prereq){
            int u = vec[1], v = vec[0];
            adj[u].push_back(v);
        }

        vector<int> indegree(n, 0);
        for(int u = 0; u < n; u++){
            for(int v : adj[u]){
                indegree[v]++;
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;

            for(int v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        return count == n;
    }
};