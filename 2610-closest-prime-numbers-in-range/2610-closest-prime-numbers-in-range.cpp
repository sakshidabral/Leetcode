class Solution {
public:
    vector<bool> helper(int right){
        vector<bool> isPrime(right+1, true);

        isPrime[0] = isPrime[1] = false;
        for(int i=2; i*i<=right; i++){
            for(int j=2; i*j<=right; j++){
                isPrime[i*j] = false;
            }
        }

        return isPrime;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime = helper(right);
        vector<int> primes;

        for(int num=left; num<=right; num++){
            if(isPrime[num]){
                primes.push_back(num);
            }
        }

        int minDiff = INT_MAX;
        vector<int> res = {-1,-1};

        for(int i=1; i<primes.size();i++){
            int diff = primes[i] - primes[i-1];
            if(diff < minDiff) {
                minDiff = diff;
                res = {primes[i-1], primes[i]};
            }
        }

        return res;
    }
};