class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> set;
        for(auto str : wordDict){
            set.insert(str);
        }

        vector<int> dp(n, -1);
        return solve(0, s, set, dp);
    }

    bool solve(int i, string s, unordered_set<string>& set, vector<int>& dp){
        if(i >= s.size()){
            return true;
        }
        if(set.find(s) != set.end()){
            return true;
        }
        if(dp[i] != -1) return dp[i];

        for(int l=1; i+l <= s.size(); l++){
            string temp = s.substr(i,l);

            if(set.find(temp) != set.end() && solve(i + l, s, set, dp)){
                return dp[i] = true;
            }
        }

        return dp[i] = false;
    }
};