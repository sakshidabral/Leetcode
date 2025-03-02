class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size();
        map<int,int> m;

        for(auto num : nums1){
            m[num[0]] += num[1]; 
        }
        for(auto num : nums2){
            m[num[0]] += num[1]; 
        }

        vector<vector<int>> ans;
        for(auto i : m) {
            ans.push_back({i.first, i.second});
        }

        return ans;
    }
};