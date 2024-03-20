class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> v;
        int index=0;
        solve(arr,v,target,index,ans);
        return ans;
    }
    void solve(vector<int>& arr, vector<int> v, int target, int index,vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(v);
            return;
        }
        //if(target<0) return; //cannot be found
        for(int i=index;i<arr.size();i++){
            if(arr[i] > target) break; 
            if(i > index && arr[i] == arr[i-1]) continue;
            v.push_back(arr[i]);
            solve(arr,v,target-arr[i],i+1,ans);
            v.pop_back();
        }
    }
};