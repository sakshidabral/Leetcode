class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPalin(i, j, s, dp)){
                    count++;
                }
            }
        }

        return count;
    }

    bool isPalin(int i, int j, string& s, vector<vector<int>>& dp){
        if(i >= j) return true;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]){
            return dp[i][j] = isPalin(i+1, j-1, s, dp);
        }

        return dp[i][j] = false;
    }
};