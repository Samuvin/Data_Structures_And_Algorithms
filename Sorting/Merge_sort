#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int lo, int mid, int end)
{
    vector<int> temp;
    int low = lo;
    int hi = mid + 1;
    while (low <= mid && hi <= end)
    {
        if (arr[low] <= arr[hi])
        {
            temp.push_back(arr[low]);
            low++;
        }
        else
        {
            temp.push_back(arr[hi]);
            hi++;
        }
    }
    while (low <= mid)
    {
        temp.push_back(arr[low]);
        low++;
    }
    while (hi <= end)
    {
        temp.push_back(arr[hi]);
        hi++;
    }
    for (int i = lo; i <= end; i++)
    {
        arr[i] = temp[i - lo];
    }
}

void merge_sort(vector<int> &arr, int lo, int hi)
{
    if (lo >= hi)
        return;
    int mid = (lo + hi) / 2;
    merge_sort(arr, lo, mid);
    merge_sort(arr, mid + 1, hi);
    merge(arr, lo, mid, hi);
}

int main()
{
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    merge_sort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    return 0;
}
