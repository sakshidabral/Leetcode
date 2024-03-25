class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int n : nums){
            m[n]++;
        }
        vector<int> v;
        for(auto i : m){
            if(i.second>=2)
            v.push_back(i.first);
        }
        return v;
    }
};