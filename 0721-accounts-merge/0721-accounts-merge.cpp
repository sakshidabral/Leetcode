class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n), rank(n, 0);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        unordered_map<string, int> m; //to store mails

        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){ //iterate for first list of emails
                string mail = accounts[i][j];
                if(m.find(mail) == m.end()){ // if mail not found
                    m[mail] = i;
                }
                else{
                    unite(i, m[mail], parent, rank);
                }
            }
        }

        vector<vector<string>> mergedMail(n);
        for(auto i : m){
            string mail = i.first;
            int node = find(i.second, parent);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergedMail[i].size() == 0){
                continue;
            }

            sort(mergedMail[i].begin(), mergedMail[i].end());

            mergedMail[i].insert(mergedMail[i].begin(), accounts[i][0]);
            ans.push_back(mergedMail[i]);
        }

        sort(ans.begin(),ans.end());

        return ans;
    }

    int find(int i, vector<int>& parent){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i], parent);
    }
    void unite(int x, int y, vector<int>& parent, vector<int>& rank){
        int xp = find(x, parent);
        int yp = find(y, parent);
        if(xp == yp) return;

        if(rank[xp] > rank[yp]){
            parent[yp] = xp;
        }
        else if(rank[xp] < rank[yp]){
            parent[xp] = yp;
        }
        else{
            parent[xp] = parent[yp];
            rank[yp]++;
        }
    }
};