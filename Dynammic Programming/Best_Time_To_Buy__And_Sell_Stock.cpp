#include <iostream>
#include <vector>
using namespace std;
int Maximum_Profit(vector<int> &prices)
{
    int mini = prices[0];
    int res = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        int curr = prices[i] - mini;
        res = max(res, curr);
        mini = min(mini, prices[i]);
    }
    return res;
}
int main()
{
    int size;
    cin >> size;
    vector<int> v(size);
    for (int i = 0; i < size; i++)
        cin >> v[i];
    cout << Maximum_Profit(v);
}
