
int LIS_product(int arr[], int n, int k)
{
    int dp[k + 1][n + 1];
    for (int j = 0; j < n + 1; j++)
        dp[0][j] = 0;
    for (int i = 0; i < k + 1; i++)
        dp[i][0] = 0;

    for (int i = 1; i < k + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            dp[i][j] = dp[i][j - 1];

            if (arr[j - 1] <= i)
            {
                dp[i][j] += dp[i / arr[j - 1]][j - 1] + 1;
            }
        }
    }
    dp[k][n];
}
