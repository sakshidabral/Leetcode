class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int bcount = 0, ans = INT_MAX;

        for(int i=0; i<blocks.size(); i++){
            if(i-k >= 0 && blocks[i-k]=='B') bcount--;
            if(blocks[i]=='B') bcount++;
            ans = min(ans, k-bcount);
        }

        return ans;
    }
};