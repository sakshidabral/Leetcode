class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(2 * total + 1, -1));
        
        return solve(0, 0, total, target, nums, dp);
    }

    int solve(int i, int sum, int total, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(i == nums.size()){
            return (sum == target) ? 1 : 0;
        }
        if(dp[i][sum + total] != -1) return dp[i][sum + total];

        int plus = solve(i+1, sum + nums[i], total, target, nums, dp);
        int minus = solve(i+1, sum - nums[i], total, target, nums, dp);

        return dp[i][sum + total] = plus + minus;
    }
};