class Solution {
public:

    typedef pair<int,int> p;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int n : nums){
            m[n]++;
        }

        priority_queue<p, vector<p>, greater<p>> pq;
        for(auto i : m){
            pq.push({i.second, i.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};