class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || nums[0]!=nums[1]) return nums[0];
        int s=0, e=n-1, mid;
        while(s<=e){
            mid=(s+e)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            if(mid%2==0){
                if(nums[mid]!=nums[mid+1]) e=mid-1;
                else s=mid+1;
                //continue;
            } else {
                if(nums[mid]!=nums[mid-1]) e=mid-1;
                else s=mid+1;
            }
        }
        return nums[mid];
    }
};