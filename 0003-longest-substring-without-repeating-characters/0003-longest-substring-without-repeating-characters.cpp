class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> set;
        int size = 0;

        int l = 0; 
        for(int r=0; r<n; r++) {
            while (set.find(s[r]) != set.end()) {
                set.erase(s[l]);  // Remove from the left until the duplicate is gone
                l++;
            }
            set.insert(s[r]);  // Insert current character
            size = max(size, r-l+1);
        }

        return size;
    }
};