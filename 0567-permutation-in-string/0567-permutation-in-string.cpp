class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f1(26,0), f2(26,0);

        for(char c : s1){
            f1[c-'a']++;
        }

        int i=0, j=0;
        while(j < s2.size()){
            f2[s2[j]-'a']++;

            if(j-i+1 > s1.size()){
                f2[s2[i]-'a']--;
                i++;
            }

            if(f1 == f2) return true;

            j++;
        }

        return false;
    }
};