#include <bits/stdc++.h>
using namespace std;

int numPairsDivisibleBy60(vector<int> &time)
{
    int map[60] = {};
    int result = 0;
    for (auto x : time)
    {
        int t = x % 60;
        int y = (60 - t) % 60;
        result += map[y];
        map[t]++;
    }
    return result;
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

    int ans = numPairsDivisibleBy60(arr);
    cout << ans << endl;
    return 0;
}