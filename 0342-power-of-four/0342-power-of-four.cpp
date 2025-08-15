class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 4){
            if(n == 1) return true;
            return false;
        }

        return (n % 4 == 0) ? isPowerOfFour(n/4) : false;
    }
};