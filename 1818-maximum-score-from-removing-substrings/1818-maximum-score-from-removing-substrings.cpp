class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        
        auto remove = [&](string& s, char first, char second, int score){
            string str;
            int points = 0;

            for(char c : s){
                if(!str.empty() && str.back() == first && c == second){
                    str.pop_back();
                    points += score;
                }
                else{
                    str.push_back(c);
                }
            }

            s = str;
            return points;
        };

        if(x > y){
            ans += remove(s,'a','b',x);
            ans += remove(s,'b','a',y);
        }
        else{
            ans += remove(s,'b','a',y);
            ans += remove(s,'a','b',x);
        }

        return ans;
    }
};