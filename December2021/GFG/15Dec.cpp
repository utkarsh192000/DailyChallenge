#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    int i = 0;
    int j = 0;
    queue<long long> q;
    vector<long long> ans;
    while (j < N)
    {
        if (A[j] < 0)
        {
            q.push(A[j]);
        }
        if (j - i + 1 == K)
        {
            if (q.size() == 0)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(q.front());
                if (A[i] == q.front())
                {
                    q.pop();
                }
            }
            i++;
        }
        j++;
    }
    return ans;
}

int main()
{
    long long n;
    cin >> n;
    long long k;
    cin >> k;
    long long arr[n];
    for (long long i = 0; i < n; i++)
    {
        long long val;
        cin >> val;
        arr[i] = val;
    }

    vector<long long> ans = printFirstNegativeInteger(arr, n, k);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}