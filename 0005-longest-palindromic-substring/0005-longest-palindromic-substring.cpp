class Solution {
public:

    bool solve(string &s, int i, int j){
        if(i >= j) return true;

        if(s[i] == s[j]) return solve(s, i+1, j-1);

        return false;
    }

    string longestPalindrome(string s) {
        //Accolite, Amazon, Groupon, MakeMyTrip, Microsoft, Qualcomm, Samsung, Visa, Walmart, Zoho
        int n =  s.size();
        
        int maxLen = INT_MIN;
        int sp = 0; // starting point

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(solve(s,i,j) == true){
                    if(j-i+1 > maxLen){
                        maxLen = j-i+1;
                        sp = i;
                    }
                }
            }
        }

        return s.substr(sp,maxLen);
    }

    
};