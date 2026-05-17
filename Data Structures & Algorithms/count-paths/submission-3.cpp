class Solution {
public:
//Math soluton(O(min(m,n))- out of m+n-2 steps, choose how many would be right(or down)
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }
        if (m < n) {
            swap(m, n);
        }

        long long res = 1;
        int j = 1;
        for (int i = m; i < m + n - 1; i++) { //calculating m+n-2Cn-1
            res *= i;
            res /= j;
            j++; // res = (m+n-2)(m+n-3)....m/(n-1)!
        }

        return res;
    }
};