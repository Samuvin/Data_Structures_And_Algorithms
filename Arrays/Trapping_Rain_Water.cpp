#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int brute_force(int arr[], int size)
{
    int result = 0;
    for (int i = 1; i < size - 1; i++)
    {
        // maximum left bar
        int left_max = arr[i];
        for (int j = 0; j < i; j++)
        {
            left_max = max(left_max, arr[j]);
        }
        int right_max = arr[i];
        for (int k = i + 1; k < size; k++)
        {
            right_max = max(right_max, arr[k]);
        }
        result += (min(left_max, right_max) - arr[i]);
    }
    return result;
}

int Better_Solution(int arr[], int size)
{
    int result = 0;
    int left_max[size];
    int right_max[size];
    left_max[0] = arr[0];
    right_max[size-1] = arr[size-1];
    for (int i = 1; i < size; i++)
    {
        left_max[i] = max(arr[i],left_max[i-1]);
    }
    for (int i = size - 2; i >= 0; i--)
    {
        right_max[i] = max(arr[i],right_max[i+1]);
    }
    for (int i = 1; i < size - 1; i++)
    {
        result += min(left_max[i], right_max[i]) - arr[i];
    }
    return result;
}

int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << Better_Solution(arr, size);
}
/*
The Question is the find the unit of water that is trapped inside a bar 
which are represented in the values in the array
Input: arr[]   = {3, 0, 2, 0, 4}
Output: 7
We can trap “3 units” of water between 3 and 2,
“1 unit” on top of bar 2 and “3 units” between 2 and 4.

The Intuition is that in the first and last bar we cant hold any water
so we do not need to start our count from it 
instead we need to start from the second bar and we have to find the left maximum bar
and the right maximum bar which prevent the water from overflow 

so we calculate minimum among the left max and right max and we subract the current bar size from the minimum
so that our water would stay in between the two bars above the current bar

*/
