class Solution {
public:
    typedef long long ll;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> set;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                ll newTarget = (ll)target - (ll)nums[i] - (ll)nums[j];
                int low = j + 1, high = n-1;
                while(low < high) {
                    if(nums[low] + nums[high] < newTarget) low++;
                    else if(nums[low] + nums[high] > newTarget) high--;
                    else {
                        set.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++;
                        high--;
                    }
                }
            }
        }

        vector<vector<int>> ans;
        for(auto s : set){
            ans.push_back(s);
        }

        return ans;
    }
};