
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i]++;
        }
        int k;
        cin >> k;

        for (int i = 0; i < n;)
        {
            cout << i + 1 << " ";
            int j = i + 1;
            int sum = arr[i];
            while (j < n && sum + arr[j] <= k)
            {
                sum += arr[j];
                j++;
            }
            cout << j << " ";
            i = j;
        }
        cout << endl;
    }
    return 0;
}
