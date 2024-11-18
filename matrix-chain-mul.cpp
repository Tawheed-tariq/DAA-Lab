#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int matrixChainOrderRec(vector<int> &p, int i, int j, vector<vector<int>> &dp) {
    if (i == j) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    dp[i][j] = INT_MAX;

    for (int k = i; k < j; k++) {
        int q = matrixChainOrderRec(p, i, k, dp) + matrixChainOrderRec(p, k + 1, j, dp) + p[i - 1] * p[k] * p[j];
        if (q < dp[i][j]) {
            dp[i][j] = q;
        }
    }

    return dp[i][j];
}

int matrixChainOrder(vector<int> &p, int n) {
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return matrixChainOrderRec(p, 1, n - 1, dp);
}

int main() {
    vector<int> p = {1, 2, 3, 4};
    int n = p.size();

    cout << "Minimum number of multiplications is " << matrixChainOrder(p, n) << endl;

    return 0;
}