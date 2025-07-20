class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int> m;
        for(char c : s){
            m[c]++;
        }

        priority_queue<pair<int,char>> pq;
        for(auto i : m){
            pq.push({i.second, i.first});
        }

        string ans;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            for(int i=0; i<curr.first; i++){
                ans += curr.second;
            }
        }

        return ans;
    }
};