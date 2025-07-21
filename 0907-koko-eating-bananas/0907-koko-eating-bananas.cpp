class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());

        while(l < r){
            int mid = (l+r)/2;
            
            if(canEatAll(piles, mid, h)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }

        return l;
    }

    bool canEatAll(vector<int>& piles, int givenHour, int h){
        int actualHour = 0;

        for(int x : piles){
            actualHour += x / givenHour;

            if(x % givenHour != 0){
                actualHour++;
            }
        }

        return actualHour <= h;
    }
};