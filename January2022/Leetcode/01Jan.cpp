#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int> &arr)
{
    int n = arr.size();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    // vector<vector<int>>dp(n*n,0);
    // vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            int max = INT_MIN;
            for (int k = i; k <= j; k++)
            {
                int left = k == i ? 0 : dp[i][k - 1];
                int right = k == j ? 0 : dp[k + 1][j];
                int kthVal = (i == 0 ? 1 : arr[i - 1]) * arr[k] * (j == n - 1 ? 1 : arr[j + 1]);

                int total = left + right + kthVal;

                if (total > max)
                {
                    max = total;
                }
            }
            dp[i][j] = max;
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    int ans = maxCoins(arr);
    cout<<ans<<endl;

    return 0;
}