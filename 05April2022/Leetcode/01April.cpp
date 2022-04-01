#include <bits/stdc++.h>
using namespace std;

// Solution 01:
void reverseString(vector<char> &s)
{
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        s.push_back(s[i]);
    }
    s.erase(s.begin(), s.begin() + n);
    return;
}

// Solution 02:
void reverseString(vector<char> &s)
{
    int n = s.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        swap(s[low], s[high]);
        low++;
        high--;
    }
    return;
}

// Solution 03:
void reverseString(vector<char> &s)
{
    reverse(s.begin(), s.end());
    return;
}


void printVector(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int n;
    cin >> n;
    vector<char> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    reverseString(s);

    return 0;
}