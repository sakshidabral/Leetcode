class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        if(n < 3) return "";

        string res;
        int max = INT_MIN;

        for(int i=0; i<=n-3; i++){
            string s = num.substr(i,3);

            if(s[0] == s[1] && s[1] == s[2]){
                int digi = stoi(s);
                if(digi > max){
                    max = digi;
                    res = s;
                }
            }            
        }

        return res;
    }
};