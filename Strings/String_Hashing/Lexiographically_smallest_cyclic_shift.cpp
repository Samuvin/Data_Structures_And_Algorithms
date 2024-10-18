//Lexiographically smallest cyclic shift
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using ll = long long;


long long quickHash(string &s, long long p, long long mod)
{
	long long res = (s[0] - 'a' + 1);
	for (int i = 1; i < s.size(); i++)
	{
		res = (res * p + (s[i] - 'a' + 1)) % mod;
	}
	return res;
}

struct Hasher
{
	int size;
	long long mod;
	long long prime;
	vector<long long>fHash;
	vector<long long>prime_power;
	void init(string s, long long _prime, long long _mod)
	{
		mod = _mod;
		prime = _prime;
		size = s.size();
		prime_power.resize(size);
		fHash.resize(size);

		fHash[0] = (s[0] - 'a' + 1);
		prime_power[0] = 1;
		for (int i = 1; i < size; i++)
		{
			fHash[i] = (fHash[i - 1] * prime + (s[i] - 'a' + 1)) % mod;
			prime_power[i] = (prime_power[i - 1] * prime) % mod;
		}
	}
	long long getFHash(int l, int r)
	{
		if (l == 0)
			return fHash[r];
		else
		{
			long long hash_value = (((fHash[r] - fHash[l - 1] * prime_power[r - l + 1]) % mod + mod)) % mod;
			return hash_value;
		}
	}
};

Hasher shash;
int n;
string str;
bool cmp(int i, int j)
{
	int lo = 1;
	int hi = n;
	int ans = 0;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (shash.getFHash(i, i + mid - 1) == shash.getFHash(j, j + mid - 1))
		{
			ans = mid;
			lo = mid + 1;
		}
		else
			hi = mid - 1;
	}
	if (ans == n)
		return 0;
	else
	{
		return str[i + ans] < str[j + ans];
	}
}

int main()
{
	cin >> str;
	n = str.size();
	str = str + str;

	shash.init(str, 31, 1e9 + 7);
	vector<int>final;
	for (int i = 0; i < n; i++)
		final.push_back(i);
	sort(final.begin(), final.end(), cmp);
	for (int i : final)
		cout << i << " ";
}
