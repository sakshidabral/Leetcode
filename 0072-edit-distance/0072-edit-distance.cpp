class Solution {
public:
    int minDistance(string w1, string w2) {
        int m = w1.size(), n = w2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, w1, w2, dp);
    }

    int solve(int i, int j, string &s1, string& s2, vector<vector<int>>& dp){
        if(i == s1.size()){
            return s2.size() - j; // insert
        }
        if(j == s2.size()){
            return s1.size() - i; // deletions
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = solve(i+1, j+1, s1, s2, dp);
        }
        
        int insert = 1 + solve(i, j+1, s1, s2, dp);
        int del = 1 + solve(i+1, j, s1, s2, dp);
        int replace = 1 + solve(i+1, j+1, s1, s2, dp);
        
        return dp[i][j] = min({insert, del, replace});
    }
};