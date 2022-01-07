#include <bits/stdc++.h>
using namespace std;

int findJudge(int n, vector<vector<int>> &trust)
{
    if (n == 1)
    {
        return 1;
    }
    int k = trust.size();
    int ans = -1;
    unordered_map<int, int> mp;
    for (int i = 0; i < k; i++)
    {
        mp[trust[i][0]]--;
        mp[trust[i][1]]++;
    }

    for (auto x : mp)
    {
        if (x.second == n - 1)
        {
            ans = x.first;
        }
    }
    return ans;
}

int main()
{
    int n=4;
    vector<vector<int>>arr={
        {1,4},
        {2,4},
        {3,4},
        {1,3},
        {3,2}
    };

    int ans=findJudge(n,arr);
    cout<<ans;

    return 0;
}