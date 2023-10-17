#include <iostream>
using namespace std;

int check(long long n, long long m, long long mid)
{
    long long sum = 1;
    for (int i = 1; i <= n; i++)
    {
        sum *= mid;
        if (sum > m)
        {
            return 2;
        }
    }
    if (sum == m)
        return 1;
    else
    {
        return 0;
    }
}

int findNthRoot(long long n, long long m)
{
    int lo = 1;
    int hi = m;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        int chunk = check(n, m, mid);
        if (chunk == 1)
        {
            return mid;
        }
        (chunk == 0) ? lo = mid + 1 : hi = mid - 1;
    }
    return -1;
}

int main()
{
    long long n, m;
    cin >> n >> m;
    cout << findNthRoot(n, m) << "\n";
}
