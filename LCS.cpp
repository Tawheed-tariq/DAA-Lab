#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int LCSLength(string s1, string s2,int m, int n, vector<vector<int>> &dp){
    if(m == 0 || n == 0){
        return 0;
    }
    if(dp[m][n] != -1){
        return dp[m][n];
    }
    if(s1[m-1] == s2[n-1]){
        dp[m][n] = 1 + LCSLength(s1, s2, m-1, n-1, dp);
    }
    else{
        dp[m][n] = max(LCSLength(s1, s2, m-1, n, dp), LCSLength(s1, s2, m, n-1, dp));
    }
    return dp[m][n]=]\
    [
        [\
        ]7]
}

int main(){
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    //here the longest common subsequence is "GTAB" of length 4
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

    int len = LCSLength(s1, s2, m, n, dp);
    cout<<len<<endl;
    return 0;
}
