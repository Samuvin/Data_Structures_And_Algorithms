#include <bits/stdc++.h>
using namespace std;

string retracePath(int destR, int destC, int srcR, int srcC, const vector<vector<int>> &directionMapping, const vector<int> &dirR, const vector<int> &dirC, const string &directions)
{
    string path = "";
    int r = destR, c = destC;
    while (r != srcR || c != srcC)
    {
        int dir = directionMapping[r][c];
        path += directions[dir];
        r -= dirR[dir];
        c -= dirC[dir];
    }
    reverse(path.begin(), path.end());
    return path;
}