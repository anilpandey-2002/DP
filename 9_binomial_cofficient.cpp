
long long nCr(int n, int r)
{
    // code here
    const long long mod = 1e9 + 7;
    vector<long long> v(r + 1, 0);
    v[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(r, i); j > 0; j--)
        {
            v[j] = (v[j] + v[j - 1]) % mod;
        }
    }
    return v[r];
}
