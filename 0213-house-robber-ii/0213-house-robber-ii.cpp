class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp1(n+1, -1), dp2(n+1, -1);
        int zero_house = solve(0, n-2, dp1, nums);
        int first_house = solve(1, n-1, dp2, nums);

        return max(zero_house, first_house);
    }

    int solve(int i, int end, vector<int>& dp, vector<int>& nums){
        if(i > end) return 0;
        if(dp[i] != -1) return dp[i];

        int take = solve(i+2, end, dp, nums) + nums[i];
        int skip = solve(i+1, end, dp, nums);

        return dp[i] = max(take, skip);
    }
};