class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());

        solve(0, target, temp, res, nums);
        return res;
    }

    void solve(int i, int target, vector<int>& temp, vector<vector<int>>& res, vector<int>& nums){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        if(target < 0 || i == nums.size()){
            return;
        }

        for(int j=i; j<nums.size(); j++){
            if(j > i && nums[j] == nums[j-1]){
                continue;
            }
            if(nums[i] > target) return;

            temp.push_back(nums[j]);
            solve(j+1, target-nums[j], temp, res, nums);
            temp.pop_back();
        }

    }
};