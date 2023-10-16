#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int lo = 0;
    int hi = nums.size() - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        (nums[mid] >= target) ? hi = mid - 1 : lo = mid + 1;
    }
    return lo;
}

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    cout<<searchInsert(v,target);
}
