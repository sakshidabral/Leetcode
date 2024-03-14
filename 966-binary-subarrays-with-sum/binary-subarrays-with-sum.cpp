class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> m;
        m[0]=1;
        int ps=0, count=0;//ps=prefix sum
        int n=nums.size();
        for(int i=0;i<n;i++){
            ps+=nums[i];
            if(m[ps-goal]) count+=m[ps-goal];
            m[ps]++;
        }
        return count++;
    }
};