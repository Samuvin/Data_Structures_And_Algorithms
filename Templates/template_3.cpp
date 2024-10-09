#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
 
#define ll long long
typedef unsigned long long ull;
typedef long double lld;
 
#define print(a)          \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl
#define print_upto(a, n)        \
    for (ll i = 1; i <= n; i++) \
        cout << a[i] << " ";    \
    cout << endl
#define take(a, n)              \
    for (ll i = 1; i <= n; i++) \
        cin >> a[i];
 
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"
#define watch3(x, y, z) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << " and " << (#z) << " is " << (z) << "\n"
#define watch4(x, y, z, u) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << " and " << (#z) << " is " << (z) << " and " << (#u) << " is " << (u) << "\n"
 
void my_debugger(string s, int LINE_NUM)
{
    cerr << endl;
}
template <typename start, typename... end>
void my_debugger(string s, int LINE_NUM, start x, end... y)
{
    if (s.back() != ',')
    {
        s += ',';
        cerr << "LINE(" << LINE_NUM << "): ";
    }
    int i = s.find(',');
    cerr << s.substr(0, i) << " = " << x;
    s = s.substr(i + 1);
    if (!s.empty())
        cerr << ", ";
    my_debugger(s, LINE_NUM, y...);
}
 
#ifndef ONLINE_JUDGE
#define debug(...) my_debugger(#__VA_ARGS__, __LINE__, __VA_ARGS__);
#else
#define debug(...)
#endif
 
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
 
#define ff first
#define ss second
#define null NULL
#define all(c) (c).begin(), (c).end()
#define allr(c) (c).rbegin(), (c).rend()
#define nl "\n"
 
#define ld long double
#define eb emplace_back
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define MOD 1000000007
#define MOD2 998244353
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define set_bits(n) __builtin_popcountll(n)
#define inf 1e17
 
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> ppll;
 
#ifndef ONLINE_JUDGE
#define debug2(x)      \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug2(x)
#endif
 
#ifndef ONLINE_JUDGE
#define output_case_number(x) cerr << "\n\nCase : " << x << nl;
#else
#define output_case_number(x)
#endif
 
void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }
 
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
 
// cout << fixed << setprecision(15) << ans << nl;
// cout << "Case #" << Q << ": ";
 
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// auto dist = uniform_int_distribution<int>(l, r);
// ll random_val = dist(rng);
 
const ll N = 200009;
ll Q = 0;
 
void solve()
{
    
}
 
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    ll T = 1;
    
    auto start1 = high_resolution_clock::now();
 
    while (T--)
    {
        Q++;
        // output_case_number(Q);
        solve();
    }
 
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    // cerr << "Time: " << duration.count() / 1000 << endl;
    return 0;
}
