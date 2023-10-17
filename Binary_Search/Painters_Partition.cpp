#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
bool predicate(const vector<int> &boards, int amount, int painter)
{
    int noOfPainter = 1;
    int sum = 0;
    for (auto i : boards)
    {
        if (sum + i > amount)
        {
            noOfPainter++;
            sum = i;
        }
        else
        {
            sum += i;
        }
    }
    return noOfPainter <= painter;
}
int Painters_Partition(vector<int> &boards, int painter)
{
    if (painter > boards.size())
        return -1;
    int lo = *max_element(boards.begin(), boards.end());
    int hi = accumulate(boards.begin(), boards.end(), 0);
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (predicate(boards, mid, painter))
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
    int size, painter;
    cin >> size >> painter;
    vector<int> boards(size);
    for (int i = 0; i < size; i++)
        cin >> boards[i];
    cout << Painters_Partition(boards, painter);
}
