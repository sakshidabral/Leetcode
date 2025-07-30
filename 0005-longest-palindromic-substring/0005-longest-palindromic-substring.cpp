class Solution {
public:
    string longestPalindrome(string s) {
        int n =  s.size();
        int maxLen = INT_MIN;
        int sp = 0; // starting point
        vector<vector<int>> dp(n, vector<int>(n,-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(solve(s,i,j,dp) == true){
                    if(j-i+1 > maxLen){
                        maxLen = j-i+1;
                        sp = i;
                    }
                }
            }
        }

        return s.substr(sp,maxLen);
    }

    bool solve(string &s, int i, int j, vector<vector<int>>& dp){
        if(i >= j) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) return dp[i][j] = solve(s, i+1, j-1, dp);

        return dp[i][j] = 0;
    }
    
};