#include <iostream>
#include <numeric>
#include <chrono>
#include <cstring>
#include <random>

#include <vector>
#include <algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<bitset>
#include<queue>
#include<stack>
#include<utility>

using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define eb emplace_back
#define pf push_front
#define ff first
#define ss second
#define mp make_pair
#define sz(x) (int)(x).size()
#define endl "\n"
#define int long long
#define ll long long
#define pii pair<int, int>
#define pcc pair<char, char>

#define mod 1000000007


#define srt(x) sort(x.begin(), x.end())
#define srtr(x) sort(x.begin(), x.end(), greater<int>())
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(),x.rend()


void Solve()
{

}


signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    auto duration = chrono::duration_cast<chrono::microseconds>(begin - end);
    cerr << "Time: " << duration.count() / 1000 << endl;
    return 0;
}
