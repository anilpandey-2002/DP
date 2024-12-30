
#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> &col_sum, int c)
{
    int mx = INT_MIN;
    int curr_sum = 0;
    for (int i = 0; i < c; i++)
    {
        curr_sum += col_sum[i];
        mx = max(mx, curr_sum);
        if (curr_sum < 0)
            curr_sum = 0;
    }
    return mx;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long r, c;
        cin >> r >> c;
        long long arr[r][c];
        memset(arr, 0, sizeof(arr));

        for (long long i = 0; i < r; i++)
        {
            for (long long j = 0; j < c; j++)
            {
                cin >> arr[i][j];
            }
        }

        int mx = INT_MIN;
        for (long long row_lim = 0; row_lim < r; row_lim++)
        {
            vector<int> col_sum(c, 0);
            for (long long row_curr = row_lim; row_curr < r; row_curr++)
            {
                for (long long col = 0; col < c; col++)
                {
                    col_sum[col] += arr[row_curr][col];
                }
                mx = max(mx, kadane(col_sum, c));
            }
        }
        cout << mx << endl;
    }
}
