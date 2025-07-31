class Solution {
public:
    int numDistinct(string s, string t) {
        int l1 = s.size(), l2 = t.size();
        if(l2 > l1) return 0;

        vector<vector<long>> dp(l1 + 1, vector<long>(l2 + 1, -1));
        return solve(0, 0, l1, l2, s, t, dp);
    }

    int solve(int i, int j, int& l1, int& l2, string& s, string& t,vector<vector<long>> &dp){
        if(j == l2) return 1;
        if(i == l1) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            int take = solve(i+1, j+1, l1, l2, s, t, dp);
            int skip = solve(i+1, j, l1, l2, s, t, dp);
            return dp[i][j] = take + skip;
        }
        else{
            return dp[i][j] = solve(i+1, j, l1, l2, s, t, dp);
        }
    }
};