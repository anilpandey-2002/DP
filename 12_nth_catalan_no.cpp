
int nth_catalan(int n)
{
    if (n <= 1)
        return 1;

    int ans = 0;
    int m = n - 1;
    for (int i = 0; i < n; i++)
    {
        ans += nth_catalan(i) * nth_catalan(m - i);
    }
    return ans;
}
