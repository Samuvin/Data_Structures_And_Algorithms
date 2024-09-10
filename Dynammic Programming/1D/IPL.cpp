#include <iostream>      // For std::cerr
#include <random>        // For std::mt19937_64
#include <chrono>        // For std::chrono
#include<algorithm>
using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int recurc(vector<int>&v, int i)
{
	if (i <= 2)
		return v[i];
	return min({recurc(v, i - 1), recurc(v, i - 2), recurc(v, i - 3)}) + v[i];
}
vector<int>dp;
int memo(vector<int>&v, int i)
{
	if (i <= 2)
		return v[i];
	int &state = dp[i];
	if (state != -1)
		return state;
	return state = min({recurc(v, i - 1), recurc(v, i - 2), recurc(v, i - 3)}) + v[i];
}
int tab(vector<int>&v)
{
	int n = v.size();
	dp[0] = v[0];
	dp[1] = v[1];
	dp[2] = v[2];
	for (int i = 3; i < n; i++)
		dp[i] = min({dp[i - 1], dp[i - 2], dp[i - 3]}) + v[i];
	return min({dp[n - 1], dp[n - 2], dp[n - 3]});
}
int space_optimised(vector<int>&v) {
	int n = v.size();
	int a = v[0];
	int b = v[1];
	int c = v[2];
	for (int i = 3; i < n; i++)
	{
		int curr = min({a, b, c}) + v[i];
		a = b;
		b = c;
		c = curr;
	}
	return min({a, b, c});
}
int main()
{
	auto begin = std::chrono::high_resolution_clock::now();
	int n;
	cin >> n;
	vector<int>v(n);
	for (int &i : v)
		cin >> i;
	dp.assign(n, -1);
	cout << accumulate(v.begin(),v.end(),0)-space_optimised(v);
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

	return 0;
}
//https://www.codechef.com/practice/course/dynamic-programming/INTDP01/problems/ZCO14004
