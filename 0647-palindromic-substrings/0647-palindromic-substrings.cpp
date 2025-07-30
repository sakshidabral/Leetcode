class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int i = 0, j = 0;
        int count = 0;

        while(i < n){
            string str = s.substr(i, j-i+1);
            if(isPalin(str)) count++;
            j++;
            if(j == n){
                i++;
                j = i;
            }
        }

        return count;
    }

    bool isPalin(string s){
        int i = 0, j = s.size()-1;
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};