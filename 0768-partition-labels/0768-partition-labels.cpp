class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> res;
        vector<int> last(26);

        for(int i=0; i<n; i++){
            last[s[i]-'a'] = i;
        }

        int i = 0, j = 0;
        for(int k=0; k<n; k++){
            j = max(j, last[s[k]-'a']);

            if(k == j){
                res.push_back(j - i + 1);
                i = k+1;
            }
        }

        return res;
    }
};