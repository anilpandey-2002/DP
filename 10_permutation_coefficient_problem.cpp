
int recur(int n, int r)
{
    if (n < r)
        return 0;
    if (n == 0 || r == 0)
        return 1;

    return recur(n - 1, r) + (r * recur(n - 1, r - 1));
}
