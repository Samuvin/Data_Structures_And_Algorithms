#include <iostream>
using namespace std;
#define ll long long
ll Range_Sum(ll start, ll end)
{
    if (end < start)
        return 0;
    return (start + end) * (end - start + 1) / 2;
}
int main()
{
    ll start, end;
    cin >> start >> end;
    cout << Range_Sum(start, end) << " ";
}
