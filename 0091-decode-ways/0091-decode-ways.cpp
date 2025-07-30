class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(0, n, s, dp);
    }

    int solve(int i, int n, string s, vector<int>& dp){
        if(i == n){
            return 1;
        }
        if(s[i] == '0'){ //not possible to split
            return 0;
        }
        if(dp[i] != -1) return dp[i];

        int one = solve(i+1, n, s, dp); //only_ith_char

        int two  = 0; //i_plus1_char
        if(i + 1 < n){
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')){
                two = solve(i+2, n, s, dp);
            }
        }

        return dp[i] = one + two;
    }
};