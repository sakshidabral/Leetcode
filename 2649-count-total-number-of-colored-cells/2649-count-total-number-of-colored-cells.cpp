class Solution {
public:
    long long coloredCells(int n) {
        /*
        Added cells follows an arithmetic sequence: 4, 8, 12, 16, ...
        which can be represented as 4 * (1, 2, 3, 4, ...)
        For minute n, the number of added cells is 4 * (n-1)
        The total no. of added cells is the sum of this sequence: 4 * (1 + 2 + ... + (n-1))
        This sum is calculated by the formula: 4 * ((n-1) * n / 2)
        Therefore, the total number of cells at minute n is: 1 + 4 * (n * (n-1) / 2)
        */
        return 1 + 4LL * n * (n-1) / 2;
    }
};