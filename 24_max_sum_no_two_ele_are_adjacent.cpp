

int FindMaxSum(int arr[], int n)
{
    int incl = arr[0];
    int excl = 0;

    for (int i = 1; i < n; i++)
    {
        int temp = max(incl, excl);

        incl = excl + arr[i];
        excl = temp;
    }

    return max(incl, excl);
}

int main()
{
    int arr[] = {5, 5, 10, 100, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d n", FindMaxSum(arr, n));
    return 0;
}
