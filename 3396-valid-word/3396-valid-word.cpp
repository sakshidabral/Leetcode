class Solution {
public:
    bool isValid(string word) {
        int n = word.size();

        if(n < 3) return false;
        int vow = 0, con = 0, digi = 0, other = 0;
        for(char c : word){
            c = tolower(c);
            if(isdigit(c)) digi++;
            else if(c=='a'||c=='e'|| c=='i'||c=='o'||c=='u') vow++;
            else if(isalpha(c)) con++;
            else other++;
        }
        if(other > 0) return false;
        if(vow == 0 || con==0) return false;

        return true;
    }
};