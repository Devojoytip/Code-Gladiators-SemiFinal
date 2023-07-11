#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1000000007;

ll int recur(int n, int k, const string& s, int idx, vector<ll int>& dp) 
{
    if (idx >= n) return 1;
    
    if (s[idx] == '0') return 0;

    if (dp[idx] != -1) return dp[idx];

    ll int cnt = 0;
    ll int num = 0;
    
    for (int i = idx; i < n; i++) 
    {
        int digit=s[i]-'0';
        num = num * 10 + digit;

        if (num > k) break;

        cnt = (cnt % MOD + recur(n, k, s, i + 1, dp) % MOD) % MOD;
    }

    dp[idx] = cnt % MOD;
    return dp[idx];
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<ll int> dp(n+1, -1);
    int result = recur(n, k, s, 0, dp);
    cout << result % MOD << endl;

    return 0;
}