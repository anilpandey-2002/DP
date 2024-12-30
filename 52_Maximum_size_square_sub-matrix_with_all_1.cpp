

class Solution
{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = mat[i][0];
        }
        for (int j = 0; j < m; j++)
        {
            dp[0][j] = mat[0][j];
        }
        int mx = INT_MIN;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {

                if (mat[i][j] == 1)
                {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
                else
                    dp[i][j] = 0;
                mx = max(mx, dp[i][j]);
            }
        }
        return (mx == INT_MIN) ? 1 : mx;
    }
};
