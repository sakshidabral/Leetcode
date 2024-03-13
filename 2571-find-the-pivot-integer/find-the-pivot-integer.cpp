class Solution {
public:
    int pivotInteger(int n) {
        for(int i=n/3;i<=n;i++){
            int x=i, sum1=0, sum2=0;
            for(int j=1;j<=x;j++)
            sum1+=j;
            for(int k=x;k<=n;k++)
            sum2+=k;
            if(sum1==sum2) return x;
        }
        return -1;
    }
};