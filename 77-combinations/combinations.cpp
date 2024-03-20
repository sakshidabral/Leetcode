class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        solve(n,k,ans,1,comb);
        return ans;
    }
    void solve(int &n, int &k, vector<vector<int>>& ans, int ind, vector<int>& comb){
        if(comb.size()==k){
            ans.push_back(comb);
            return;
        }
        for(int i=ind;i<=n;i++){
            comb.push_back(i);
            solve(n,k,ans,i+1,comb);
            comb.pop_back();
        }
    }
};