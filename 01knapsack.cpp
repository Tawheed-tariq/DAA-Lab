#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsackRec(int W, const vector<int>& weights, const vector<int>& values, int n, vector<vector<int>>& dp) {
    if (n == 0 || W == 0) {
        return 0;
    }

    if (dp[n][W] != -1) {
        return dp[n][W];
    }

    if (weights[n - 1] <= W) {
        dp[n][W] = max(values[n - 1] + knapsackRec(W - weights[n - 1], weights, values, n - 1, dp), knapsackRec(W, weights, values, n - 1, dp));
    } else {
        dp[n][W] = knapsackRec(W, weights, values, n - 1, dp);
    }

    return dp[n][W];
}

int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    return knapsackRec(W, weights, values, n, dp);
}

int main() {
    int W = 50; 
    vector<int> weights = {10, 20, 30}; 
    vector<int> values = {60, 100, 120}; 
    int n = weights.size(); 

    cout << "Maximum value in Knapsack = " << knapsack(W, weights, values, n) << endl;

    return 0;
}