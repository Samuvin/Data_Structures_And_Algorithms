#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int findMin(vector<int> &nums)
{
    int lo = 0;
    int ans = INT_MAX;
    int hi = nums.size() - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (nums[lo] <= nums[mid])
        {
            ans = min(ans, nums[lo]);
            lo = mid + 1;
        }
        else
        {
            ans = min(ans, nums[mid]);
            hi = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << findMin(v) << endl;
}
