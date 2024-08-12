#include <iostream>      // For std::cerr
#include <random>        // For std::mt19937_64
#include <chrono>        // For std::chrono
#define int long long
using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

signed main()
{
	auto begin = std::chrono::high_resolution_clock::now();
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int res = 0;
		int l = max(0ll, n - m);
		int r = m + n;
		for (int i = 0; i <= 31; i++)
		{
			if ((l & (1ll << i)) || (r & (1ll << i)))
				res |= (1ll << i);
			else if ((r - l) >= (1ll << i) )
			{
				res |= (1ll << i);
			}
		}
		cout << res << "\n";
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

	return 0;
}
