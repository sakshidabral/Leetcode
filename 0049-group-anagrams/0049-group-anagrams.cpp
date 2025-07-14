class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> m;

        for(int i=0; i<n;i++){
            string s = strs[i];
            sort(begin(s), end(s));

            m[s].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for(auto i : m){
            res.push_back(i.second);
        }

        return res;

    }
};