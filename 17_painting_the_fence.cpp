
long long const mod = 1e9 + 7;
long long countWays(int n, int k)
{
    long long dp[n + 1];
    memset(dp, 0, sizeof(dp));
    // base condition
    dp[1] = k;
    dp[2] = (k + ((k - 1) * k) % mod) % mod;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = ((k - 1) * ((dp[i - 1] + dp[i - 2]) % mod)) % mod;
    }
    return dp[n];
}
