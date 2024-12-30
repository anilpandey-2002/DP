

const long long mod = 1e9 + 7;
long long dp[1002][1002];
int helper(string &s, int i, int j)
{
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        return 1;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j] % mod;
    }
    if (s[i] == s[j])
    {

        dp[i][j] = (1 + helper(s, i + 1, j) % mod + helper(s, i, j - 1) % mod) % mod;
    }
    else
    {

        dp[i][j] = (helper(s, i, j - 1) % mod + helper(s, i + 1, j) % mod - helper(s, i + 1, j - 1) % mod) % mod;
    }
    return dp[i][j] % mod;
}
long long int countPS(string str)
{
    memset(dp, -1, sizeof(dp));
    return helper(str, 0, str.size() - 1) % mod;
}
