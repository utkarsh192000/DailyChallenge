#include <bits/stdc++.h>
using namespace std;

int kThSmallestFactor(int n, int k)
{
    // code here
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
            {
                pq.push(i);
            }
            else
            {
                pq.push(i);
                pq.push(n / i);
            }
        }
    }
    for (int i = 1; i < k; i++)
    {
        pq.pop();
        if (pq.empty())
        {
            return -1;
        }
    }
    return pq.top();
}

int main()
{
    int n, k;
    cin >> n >> k;

    int ans = kThSmallestFactor(n, k);
    cout << ans << endl;
    return 0;
}