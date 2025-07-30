class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int m = t1.size(), n = t2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));

        return lcs(m, n, t1, t2, dp);
    }
    int lcs(int m, int n, string& s1, string& s2, vector<vector<int>>& dp){
        if(m==0 || n==0) return dp[m][n] = 0;
        if(dp[m][n] != -1) return dp[m][n];

        if(s1[m-1] == s2[n-1]){
            return 1 + lcs(m-1, n-1, s1, s2, dp);
        }

        return dp[m][n] = max( lcs(m-1, n, s1, s2, dp), lcs(m, n-1, s1, s2, dp));
    }
};