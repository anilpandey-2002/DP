
int MCM(string s)
{
    int n = s.size();
    bool dp[n][n];

    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = true;
            }
            else if (gap == 1)
            {
                dp[i][j] = (s[i] == s[j]);
            }
            else
            {
                if (s[i] == s[j] && dp[i + 1][j - 1] == true)
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
    }

    int cut[n];
    cut[0] = 0;
    for (int gap = 1; gap < n; gap++)
    {
        if (dp[0][gap])
            cut[gap] = 0;
        else
        {
            int mn = INT_MAX;
            for (int i = gap; i >= 0; i--)
            {
                if (dp[i][gap])
                {
                    mn = min(mn, cut[i - 1]);
                }
            }
            cut[gap] = mn + 1;
        }
    }

    return cut[n - 1];
}
