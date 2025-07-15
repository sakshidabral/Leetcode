class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, maxx = 0;
        vector<int> freq(26,0);

        for(int r=0; r<n; r++){
            char c = s[r];
            freq[c-'A']++;
            maxx = max(maxx, freq[c-'A']);

            if(r-l+1 - maxx > k){
                freq[s[l]-'A']--;
                l++;
            }
        }

        return n-l;
    }
};