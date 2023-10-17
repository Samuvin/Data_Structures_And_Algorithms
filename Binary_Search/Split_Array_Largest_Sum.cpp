#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool predicate(const vector<int> &arr, int amount, int split)
{
    int noOfsplit = 1;
    int sum = 0;
    for (auto i : arr)
    {
        if (sum + i > amount)
        {
            noOfsplit++;
            sum = i;
        }
        else
        {
            sum += i;
        }
    }
    return noOfsplit <= split;
}
int split_array(vector<int> &arr, int split)
{
    if (split > arr.size())
        return -1;
    int lo = *max_element(arr.begin(), arr.end());
    int hi = accumulate(arr.begin(), arr.end(), 0);
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (predicate(arr, mid, split))
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return lo;
}

int main()
{
    int size, split;
    cin >> size >> split;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << split_array(arr, split);
}
