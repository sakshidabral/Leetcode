class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> temp;

        solve(0, target, temp, res, nums);

        return res;
    }

    void solve(int i, int target, vector<int>& temp, vector<vector<int>>& res, vector<int>&nums){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        if(i == nums.size() || target < 0){
            return;
        }
        

        solve(i+1, target, temp, res, nums);

        if(nums[i] <= target){
            temp.push_back(nums[i]);
            solve(i, target-nums[i], temp, res, nums);
            temp.pop_back();
        }
    }
};