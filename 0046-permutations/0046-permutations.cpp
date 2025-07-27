class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        solve(0, nums, res);
        return res;
    }

    void solve(int i, vector<int> nums, vector<vector<int>>& res){
        if(i == nums.size()){
            res.push_back(nums);
            return;
        }

        for(int j=i; j<nums.size(); j++){
            swap(nums[i], nums[j]);
            solve(i+1, nums, res);
            swap(nums[i], nums[j]); // backtrack
        }
    }
};