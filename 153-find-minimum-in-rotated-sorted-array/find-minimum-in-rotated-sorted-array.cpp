class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        if(nums.size()==1) return nums[0];
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>nums[mid+1]) return nums[mid+1];
            else if(mid==0 && nums[mid]<nums[mid+1]) return nums[mid];
            else if(nums[r]>nums[mid]) r=mid;
            else if(nums[mid]>nums[r] && nums[mid]>nums[l]) l=mid+1;
            else r=mid;
        }
        return -1;
    }
};