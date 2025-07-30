class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int L=1; L<=n; L++){
            for(int i=0; i+L-1 < n; i++){
                int j = i + L - 1;

                if(i == j){
                    dp[i][j] = true;
                }
                else if(i+1 == j){
                    dp[i][j] = (s[i] == s[j]);
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1]){
                        dp[i][j] = true;
                    }
                }

                if(dp[i][j] == true){
                    count++;
                }
            }
        }

        return count;
    }
};