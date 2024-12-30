

int maxSubstring(string s)
{
    int len = s.size();
    int dp[len];
    dp[0] = (s[0] == '1') ? -1 : 1;
    int omax = dp[0];
    for (int i = 1; i < len; i++)
    {
        if (s[i] == '1')
        {
            dp[i] = max(-1, dp[i - 1] - 1);
        }
        else
        {
            dp[i] = max(1, dp[i - 1] + 1);
        }
        omax = max(omax, dp[i]);
    }
    return omax;
}
