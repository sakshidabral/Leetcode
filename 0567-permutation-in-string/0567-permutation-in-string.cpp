class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size(), l2 = s2.size();
        if(l1 > l2) return false;

        sort(begin(s1), end(s1));

        for(int l=0; l<=l2-l1; l++){
            string s = s2.substr(l,l1);
            sort(begin(s), end(s));

            if(s == s1) return true;
        }

        return false;
    }
};