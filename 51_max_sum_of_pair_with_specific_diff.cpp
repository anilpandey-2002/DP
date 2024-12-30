

int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i < n + 1; i++)
    {

        if (arr[i - 1] - arr[i - 2] < k)
        {
            dp[i] = max(dp[i - 1], arr[i - 1] + arr[i - 2] + dp[i - 2]);
        }
        else
            dp[i] = dp[i - 1];
    }
    return dp[n];
}
