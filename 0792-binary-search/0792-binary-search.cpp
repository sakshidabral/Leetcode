class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        return binary(l,r,target,nums);
    }
    int binary(int l, int r, int key, vector<int>& nums){
        if(l > r) return -1;

        int mid = (l+r)/2;
        if(key == nums[mid]) return mid;

        if(key > nums[mid]){
            return binary(mid+1,r,key,nums);
        }
        return binary(l,mid-1,key,nums);
        
    }
};