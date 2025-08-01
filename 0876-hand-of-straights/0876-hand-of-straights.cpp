class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gsize) {
        int n = hand.size();
        if(n % gsize != 0) return false;

        map<int,int> m;
        for(int c : hand){
            m[c]++;
        }

        for(auto i : m){
            if(i.second > 0){
                int count = i.second;

                for(int j=0; j < gsize; j++){
                    if(m[i.first + j] < count){
                        return false;
                    }

                    m[i.first + j] -= count;
                } 
            }
        }

        return true;
    }
};