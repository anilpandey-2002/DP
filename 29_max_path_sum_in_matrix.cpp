

int maximumPath(int n, vector<vector<int>> mat)
{
    int omax = 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int j = 0; j < n; j++)
    {
        dp[0][j] = mat[0][j];
        omax = max(omax, dp[0][j]);
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a = 0, b = dp[i - 1][j], c = 0;
            if (j - 1 >= 0)
                a = dp[i - 1][j - 1];
            if (j + 1 < n)
                c = dp[i - 1][j + 1];

            dp[i][j] = mat[i][j] + max({a, b, c});
            omax = max(omax, dp[i][j]);
        }
    }
    return omax;
}
