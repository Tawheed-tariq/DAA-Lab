#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int matrixChainOrder(vector<int> &p, int n) {
    vector<vector<int>> m(n, vector<int>(n, 0));

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    return m[1][n - 1];
}

int main() {
    vector<int> p = {1, 2, 3, 4};
    int n = p.size();

    cout << "Minimum number of multiplications is " << matrixChainOrder(p, n) << endl;

    return 0;
}