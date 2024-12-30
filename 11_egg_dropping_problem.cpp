

int eggDrop(int given_egg, int given_floor)
{
    if (given_floor == 0 || given_floor == 1 || given_egg == 1)
        return given_floor;

    int ans = INT_MAX - 1;

    for (int k = 1; k <= given_floor; k++)
    {
        int temp = max(eggDrop(given_egg - 1, k - 1), eggDrop(given_egg, given_floor - k));

        ans = min(temp, ans);
    }
    return ans;
}
