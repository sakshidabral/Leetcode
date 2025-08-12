class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<long long> powers;

        for(int i=1; i<=n; i++){
            long long val = pow(i,x);
            if(val <= n){
                powers.push_back(val);
            }
        }

        int m = powers.size();
        vector<vector<int>> dp(m, vector<int>(n+1, -1));

        return solve(0, n, powers, dp);
    }

    int solve(int i, int num, vector<long long>& powers, vector<vector<int>>& dp){
        if(num == 0){
            return 1;
        }
        if(num < 0 || i == powers.size()){
            return 0;
        }
        if(dp[i][num] != -1) return dp[i][num];

        int take = solve(i+1, num-powers[i], powers, dp);
        int skip = solve(i+1, num, powers, dp);

        long long ans = (take + skip) % (1000000007);
        return dp[i][num] = (int)ans;
    }
};