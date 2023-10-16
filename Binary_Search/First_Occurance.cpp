#include <iostream>
#include <vector>
using namespace std;

int first_occurance(vector<int> &arr, int target)
{
    int lo = 0;
    int hi = arr.size() - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] >= target)
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

int last_occurance(vector<int> &arr, int target)
{
    int lo = 0;
    int hi = arr.size() - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] <= target)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return hi;
}
int count(vector<int> &arr, int n, int target)
{
    int x = first_occurance(arr, target);
    int y = last_occurance(arr, target);
    int ans = 0;
    if (x >= 0 && x < arr.size() && arr[x] == target)
    {
        ans = y - x + 1;
    }
    return ans;
}
int main()
{
    int n,target;
    cin>>n>>target;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<count(v,n,target);
}
