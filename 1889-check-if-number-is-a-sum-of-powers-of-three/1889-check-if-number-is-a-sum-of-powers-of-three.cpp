class Solution {
public:
    bool checkPowersOfThree(int n) {
        int pow = 0;
        while(n>2){
            if(n%3 == 0 || (n-1)%3==0){
                n = n/3;
            }
            else break;
        }
        return (n == 1) ? true : false;
    }
};