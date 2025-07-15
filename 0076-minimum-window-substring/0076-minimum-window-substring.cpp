class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        vector<int> freq(128,0), windowFreq(128,0);
        for(char c : t){
            freq[c]++;
        }

        int l=0, r=0, min = INT_MAX, start = 0;
        int req = t.size(), formed = 0;
        int n = s.size();

        while(r < n){
            char c = s[r];
            windowFreq[c]++;
            if(freq[c]>0 && windowFreq[c] <= freq[c]){
                formed++;
            }

            while(formed == req){
                //update ans
                if(r-l+1 < min){
                    min = r-l+1;
                    start = l;
                }

                //contract from left
                char ch = s[l];
                windowFreq[ch]--;
                if(freq[ch]>0 && windowFreq[ch] < freq[ch]){
                    formed--;
                }
                l++;
            }
            r++;
            
        }

        return min == INT_MAX ? "" : s.substr(start,min);
    }
};