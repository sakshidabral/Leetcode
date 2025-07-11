class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int n : nums){
            m[n]++;
        }
        
        for(auto i : m){
            if(i.second > 1) return true;
        }

        return false;
    }
};