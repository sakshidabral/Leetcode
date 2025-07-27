class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        
        sort(nums.begin(), nums.end());
        
        solve(temp,nums,res,0);
        return res;
    }
    void solve(vector<int>& temp, const vector<int>& nums, vector<vector<int>>& res, int idx) {
        res.push_back(temp); // empty subset

        for(int i=idx; i<nums.size(); i++) {
            if(i>idx && nums[i] == nums[i-1]){ // Skip duplicates
                continue; 
            }

            temp.push_back(nums[i]);
            solve(temp, nums, res, i+1);
            temp.pop_back();
        }
    }
};