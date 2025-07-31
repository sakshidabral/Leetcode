class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        return burst(nums, 1, n, dp);
    }

    int burst(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int maxCoins = 0;
        for (int k = i; k <= j; ++k) {
            int left = burst(nums, i, k - 1, dp);
            int right = burst(nums, k + 1, j, dp);
            int coins = left + right + (nums[i-1] * nums[k] * nums[j+1]);

            maxCoins = max(maxCoins, coins);
        }

        return dp[i][j] = maxCoins;
    }
};
