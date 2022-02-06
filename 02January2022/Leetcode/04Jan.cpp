#include <bits/stdc++.h>
using namespace std;

int bitwiseComplement(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int ans = 0;
    int weight = 1;
    while (n > 0)
    {
        if ((n & 1) == 0)
        {
            ans += weight;
        }
        n = n >> 1;
        weight = weight << 1;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int ans=bitwiseComplement(n);
    cout<<ans<<endl;

    return 0;
}