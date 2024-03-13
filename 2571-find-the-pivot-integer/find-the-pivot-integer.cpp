class Solution {
public:
    int pivotInteger(int n) {
        /*1) 1->x = x(x+1)/2
          2) x->n = (1->n)-(1->(x-1))
          1 and 2 equal
          x^2=n(n+1)/2  */
        for(int i=1;i<=n;i++){
            if((i*i)==(n*(n+1))/2) return i;
        }
        return -1;
    }
};