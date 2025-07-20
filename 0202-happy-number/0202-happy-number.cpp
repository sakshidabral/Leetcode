class Solution {
public:
    bool isHappy(int n) {
        do {
            int num = n, sum = 0;
            while(num != 0){
                int r = num%10;
                sum += (r*r);
                num /= 10;
            }
            n = sum;
        } while(n > 9);
        return n == 1;
    }
};