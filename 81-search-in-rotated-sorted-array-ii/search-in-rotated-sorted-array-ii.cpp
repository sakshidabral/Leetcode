class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s=0, e=nums.size()-1;
        sort(nums.begin(),nums.end());
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]<target) s=mid+1;
            else e=mid-1;
        }
        return false;
    }
};