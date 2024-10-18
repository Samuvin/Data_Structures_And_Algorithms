#include<iostream>
#include<vector>
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


int main()
{

	string text, pattern;
	cin >> text >> pattern;
	int p = pattern.length();
	int h = quickHash(pattern, 31, 1e9 + 7);
	Hasher texth;
	texth.init(text, 31, 1e9 + 7);
	for (int i = 0; i + p - 1 < text.length(); i++)
	{
		if (h == texth.getFHash(i, i + p - 1))
			cout << "Match At " << i << "\n";
	}
}
