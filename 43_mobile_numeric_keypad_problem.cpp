

long long getCountUtil(int n)
{
    long long dp[n + 1][10];
    memset(dp, 0, sizeof(dp));

    vector<vector<int>> data;
    data.push_back({0, 8});
    data.push_back({1, 2, 4});
    data.push_back({1, 2, 3, 5});
    data.push_back({2, 3, 6});
    data.push_back({1, 4, 5, 7});
    data.push_back({2, 4, 5, 6, 8});
    data.push_back({3, 5, 6, 9});
    data.push_back({4, 7, 8});
    data.push_back({5, 7, 8, 9, 0});
    data.push_back({6, 8, 9});

    for (int j = 0; j < 10; j++)
    {
        dp[0][j] = 0;
        dp[1][j] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {

            for (int prev : data[j])
            {
                dp[i][j] += dp[i - 1][prev];
            }
        }
    }
    long long sum = 0;
    for (int j = 0; j <= 9; j++)
    {
        sum += dp[n][j];
    }
    return sum;
}
