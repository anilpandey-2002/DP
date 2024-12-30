

int maxSumWO3Consec(int arr[], int n)
{
    int sum[n];
    sum[0] = arr[0];
    sum[1] = arr[0] + arr[1];
    sum[2] = max({sum[1], arr[2] + sum[0], arr[2] + arr[1]});

    for (int i = 3; i < n; i++)
    {
        sum[i] = max({sum[i - 1], arr[i] + sum[i - 2], arr[i] + arr[i - 1] + sum[i - 3]});
    }
    return sum[n - 1];
}

int main()
{
    int arr[] = {100, 1000};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSumWO3Consec(arr, n);
    return 0;
}
