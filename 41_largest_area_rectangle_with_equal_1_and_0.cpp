
#include <bits/stdc++.h>
using namespace std;

int subsum(vector<int> &col_sum, int c)
{
    int mx = 1;
    int curr_sum = 0;
    unordered_map<int, int> m;

    for (int i = 0; i < c; i++)
    {
        curr_sum += col_sum[i];
        if (curr_sum == 0)
        {
            mx = max(mx, i + 1);
        }
        else if (m[curr_sum])
        {
            mx = max(mx, i - m[curr_sum] + 1);
        }
        else
            m[curr_sum] = i + 1;
    }
    return mx;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        int arr[r][c];
        memset(arr, 0, sizeof(arr));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == 0)
                    arr[i][j] = -1;
            }
        }

        int mx = INT_MIN;
        for (int row_lim = 0; row_lim < r; row_lim++)
        {
            vector<int> col_sum(c, 0);
            for (int row_curr = row_lim; row_curr < r; row_curr++)
            {
                for (int col = 0; col < c; col++)
                {
                    col_sum[col] += arr[row_curr][col];
                }
                mx = max(mx, subsum(col_sum, c) * (row_curr - row_lim + 1));
            }
        }
        cout << mx << endl;
    }
}
