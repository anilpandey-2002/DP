

int longestSubsequence(int n, int arr[])
{
    int dp[n];
    dp[0] = 1;
    int omax = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (abs(arr[i] - arr[j]) == 1)
            {

                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        omax = max(dp[i], omax);
    }
    return omax;
}
