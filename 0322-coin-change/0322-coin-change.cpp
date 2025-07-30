class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int res = solve(n-1, amount, coins, dp);
        return (res != 1e9) ? res : -1;
    }

    int solve(int i, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(amount == 0){
            return 0;
        }
        if(i < 0){
            return 1e9;
        }
        if(dp[i][amount] != -1) return dp[i][amount];

        int skip = solve(i-1, amount, coins, dp);

        int take = 1e9;
        if(coins[i] <= amount){
            take = 1 + solve(i, amount - coins[i], coins, dp); 
        }

        return dp[i][amount] = min(take, skip);
    }
};