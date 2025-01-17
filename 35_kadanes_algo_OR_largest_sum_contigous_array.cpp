
int maxSubarraySum(int arr[], int n)
{
    int dp[n];

    dp[0] = max(0, arr[0]);
    int omax = dp[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        omax = max(dp[i], omax);
    }
    return omax;
}
