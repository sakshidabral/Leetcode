class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int n : nums){
            sum += n;
        }
        if(sum % 2 == 1) return false;

        int x = sum / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(x+1, -1));
        return solve(0, x, nums, dp);
    }

    bool solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0){
            return true;
        }
        if(i == nums.size()){
            return false;
        }
        if(dp[i][target] != -1) return dp[i][target];

        int skip = solve(i+1, target, nums, dp);

        int take = 0;
        if(nums[i] <= target){
            take = solve(i+1, target - nums[i], nums, dp);
        }

        return dp[i][target] = skip || take;
    }
};