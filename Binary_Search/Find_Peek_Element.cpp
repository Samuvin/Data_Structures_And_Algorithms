#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int size = nums.size();
    if (size == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[size - 1] > nums[size - 2])
        return size - 1;
    int lo = 1;
    int hi = nums.size() - 2;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
        {
            return mid;
        }
        if (nums[mid] > nums[mid - 1])
        {
            lo = mid + 1;
        }
        else if (nums[mid] < nums[mid - 1])
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << findPeakElement(v);
}
