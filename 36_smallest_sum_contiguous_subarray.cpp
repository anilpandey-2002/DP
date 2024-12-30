

int maxSubarraySum(int arr[], int n)
{
    int dp[n];

    dp[0] = max(0, arr[0]);
    int omin = dp[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = min(dp[i - 1] + arr[i], arr[i]);
        omin = min(dp[i], omin);
    }
    return omin;
}
