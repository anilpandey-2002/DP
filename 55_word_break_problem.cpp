

int wordBreak(string A, vector<string> &B)
{
    set<string> s;
    for (string i : B)
        s.insert(i);

    int n = A.size();
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < i; j++)
        {

            if (dp[j] && s.find(A.substr(j, i - j)) != s.end())
            {

                dp[i] = 1;
                break;
            }
        }
    }
    return dp[n];
}
