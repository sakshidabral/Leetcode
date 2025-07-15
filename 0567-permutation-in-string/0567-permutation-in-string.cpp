class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f1(26,0);

        for(char c : s1){
            f1[c-'a']++;
        }

        int n1 = s1.size(), n2 = s2.size();
        for(int i=0; i<=n2-n1; i++){
            vector<int> f2(26,0);
            string s = s2.substr(i,n1);
            for(char c : s){
                f2[c-'a']++;
            }

            if(f1 == f2) return true;
        }

        return false;
    }
};