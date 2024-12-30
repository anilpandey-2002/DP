const long long mod = 1e9 + 7;

vector<long long> dp;
long long recur(long long n)
{
    if (dp[n] != -1)
        return dp[n];
    if (n > 2)
        return dp[n] = (recur(n - 1) % mod) + ((n - 1) * (recur(n - 2) % mod) % mod);
    return dp[n] = n;
}

long long countFriendsPairings(long long n)
{
    dp = vector<long long>(n + 1, -1);
    return recur(n) % mod;
}

int countFriendsPairings(int n)
{
    long long dp[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dp[i] = (i <= 2) ? i : (dp[i - 1] + ((i - 1) * dp[i - 2]) % mod) % mod;
    }
    return dp[n];
}
