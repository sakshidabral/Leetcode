class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i] != nums[i+1]) continue;
            nums[i] *= 2;
            nums[i+1] = 0;
        }
        int count = 0, ptr = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0) count++;
            else {
                nums[ptr] = nums[i];
                ptr++;
            }
        }
        for(int i=0;i<count;i++){
            nums[n-i-1] = 0;
        }
        return nums;
    }
};