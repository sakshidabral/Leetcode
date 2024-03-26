class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool one=false;
        int n=nums.size(),max=nums[0];
        unordered_map<int,int> m;
        for(int num : nums){
            m[num]=1;
            if(num==1) one=true;
            if(num>max) max=num;
        }
        if(!one) return 1;
        for(int i=2;i<max;i++){
            if(m.find(i)==m.end()) return i; 
        }
        return max+1;
    }
};