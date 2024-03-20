class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> per;
        unordered_map<string,int> m;
        solve(per,m,nums,0);
        return per;
    }
    void solve(vector<vector<int>>& per, unordered_map<string,int>& m, vector<int> nums, int i){
        if(i==nums.size()){
            string str="";
            for(auto s : nums){
                str+=to_string(s)+",";
            }
            if(m.find(str)==m.end()){//==m.end() means element not found
                per.push_back(nums);
                m[str]=1;
            } else m[str]++; //skip rest
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            solve(per,m,nums,i+1);
            swap(nums[i],nums[j]);
        }

    }
};