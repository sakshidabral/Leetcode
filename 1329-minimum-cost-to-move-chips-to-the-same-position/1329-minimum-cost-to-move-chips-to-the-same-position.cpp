class Solution {
public:
    int minCostToMoveChips(vector<int>& pos) {
        int even = 0, odd = 0;
        for(int chip : pos){
            if(chip%2==0) even++;
            else odd++;
        }
        if(even>odd) return odd;
        else return even;
    }
};