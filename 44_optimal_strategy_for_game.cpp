
long long maximumAmount(int arr[], int n)
{
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {
            if (gap == 0)
                dp[i][j] = arr[i];
            else if (gap == 1)
                dp[i][j] = max(arr[i], arr[j]);
            else
            {
                int a = arr[i] + min(dp[i + 1][j - 1], dp[i + 2][j]);
                int b = arr[j] + min(dp[i][j - 2], dp[i + 1][j - 1]);
                dp[i][j] = max(a, b);
            }
        }
    }
    return dp[0][n - 1];
}
