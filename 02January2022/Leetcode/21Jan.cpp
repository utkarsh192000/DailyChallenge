#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    // currentBalance - the current balance we are considering (which has to be >= 0), to reach from one gas station to another
    // remainingBalance - the balance of the remaining part (which is <= 0), total netBalance from 0 index to s-1 


    int start = 0, currentBalance = 0, remainingBalance = 0;
    
    // iterate through each gas station and update the starting point, which takes O(n) time
    for (int i = 0; i < cost.size(); i++)
    {
        // update the current gas balance while traversing 
        currentBalance += gas[i] - cost[i];

        // if the currently considering balance < 0, we can't move to the next gas station -> the current start is invalid
        if (currentBalance < 0)
        {
            start = i + 1;                      // update start to new candidate value
            // since from here we are not able to go ahead ; this means if we start from any index before it, we wont be able to reach , complete round 

            remainingBalance += currentBalance; // update the negative balance (of the remaining part)

            currentBalance = 0;                 // reset the currently considering balance as we are freshly goint ot count from here 
        }
    }
    // at the end, we check whether the positive balance (currentBalance) can compensate the remainingBalance (currentBalance + remainingBalance has to be >= 0)
    return currentBalance + remainingBalance >= 0 ? start : -1;

    // as we know that where we stopped , it was -ve balance in total , it means we must have +ve balance from that index to last 
    // because to complete whole round our netBalance of gas must be >=0 
}

int main()
{

    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    int ans = canCompleteCircuit(gas, cost);
    cout << ans;

    return 0;
}