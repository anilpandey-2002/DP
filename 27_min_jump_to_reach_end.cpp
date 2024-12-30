
int minJumps(int arr[], int n)
{
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1e6;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] >= i - j && dp[j] != 1e6)
            {
                dp[i] = min(dp[i], dp[j] + 1);
                break;
            }
        }
    }
    return (dp[n - 1] == 1e6) ? -1 : dp[n - 1];
}
