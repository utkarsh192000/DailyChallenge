#include <bits/stdc++.h>
using namespace std;

int removeDuplicate2(vector<int> &nums)
{
    int n = nums.size();
    // calculate the size of nums 
    int i = 0;
    // set a pointer which will traverse through whole array
    int oInd = 0;
    // // pointer which would help in placing the every element to atmost 2

    while (i < n)
    {
        int start = i;
        // after each new element is found set start to the that index 
        while (i < n - 1 && nums[i] == nums[i + 1])
        {
            i++;
            // we keep of moving i , tille we are finding the same element 
        }
        int len = i - start + 1;
        // calc the total count of duplicated element 
        int freq = min(len, 2);
        // calc the no. of element we must keep there itself 

        while (freq > 0)
        {
            // it time for placing atmost 2 element of each unique element 
            nums[oInd] = nums[start];
            // place it till we get our freq to 0 
            oInd++;
            // increase the oIndex 
            freq--;
            // reduce the count of freq 
        }
        i++;
        // move the i step ahead so that it start counting the next unique element 
    }
    return oInd;
    // simple return that Oindex , becauseupto that we have place atmost freq of each unique to be 
    // if we now print till this index we will get our correct array  
}

void printVector(vector<int>&arr,int k){
    for (int i = 0; i < k; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // for(int i=0;i<n;i++){
    //     cout<<nums[i]<<" ";
    // }
    // cout<<endl;

    int k = removeDuplicate2(nums);

    printVector(nums,k);

    return 0;
}