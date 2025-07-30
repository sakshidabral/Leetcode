class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, m, n, s1, s2, dp);
    }

    int solve(int i, int j, int m, int n, string& s1, string& s2, vector<vector<int>>& dp){
        if(i == m || j == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + solve(i+1, j+1, m, n, s1, s2, dp);
        }
        else{
            int move_i = solve(i+1, j, m, n, s1, s2, dp);
            int move_j = solve(i, j+1, m, n, s1, s2, dp);
            return dp[i][j] = max(move_i, move_j);
        }
        
    }
};