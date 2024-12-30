
int static memo[1001][1001];
int recur(int w, int wt[], int val[], int n)
{
    if (n == 0 || w == 0)
        return 0;
    if (memo[n][w] != -1)
        return memo[n][w];
    if (wt[n - 1] <= w)
    {
        return memo[n][w] = max(val[n - 1] + recur(w - wt[n - 1], wt, val, n - 1), recur(w, wt, val, n - 1));
    }
    else if (wt[n - 1] > w)
    {
        return memo[n][w] = recur(w, wt, val, n - 1);
    }
}
int knapSack(int w, int wt[], int val[], int n)
{
    memset(memo, -1, sizeof(memo));
    recur(w, wt, val, n);
    return memo[n][w];
}
