#include<bits/stdc++.h>
using namespace std;

struct PolyHasher
{
	int len, prime, MOD;
	vector<int> powerK, base, frev;

	void init(string s, int _prime, int _MOD)
	{
		prime = _prime, MOD = _MOD;
		len = s.length();
		powerK.resize(len + 1);
		base.resize(len + 1);

		base[0] = 0;
		powerK[0] = 1;

		for (int i = 0; i < len; i++) 
		{
			int num = (s[i] - 'a' + 1 ) % MOD;
			base[i + 1] = (1LL * base[i] * prime + num) % MOD;
			powerK[i + 1] = (1LL * prime * powerK[i]) % MOD;
		}

		frev.resize(len + 1);
		frev[len] = 0;
		for (int i = len - 1; i >= 0; i--) 
		{
			int num = (s[i] - 'a' + 1 ) % MOD;
			frev[i] = (1LL * frev[i + 1] * prime + num) % MOD;
		}
	}
	int gethash(int l, int r) 
	{ 
		int ans = (base[r + 1] - 1LL * base[l] * powerK[(r - l + 1)]) % MOD;
		return (ans + MOD) % MOD;
	}
	int getfrevhash(int l, int r) {
		int ans = (frev[l] - 1LL * frev[r + 1] * powerK[(r - l + 1)]) % MOD;
		return (ans + MOD) % MOD;
	}
};

struct Double_Hasher 
{
	PolyHasher a, b;
	void init(string s)
	{
		a.init(s, 37, 1000000021);
		b.init(s, 39, 1000000009);
	}
	pair<int, int> gethash(int l, int r) 
	{
		return {a.gethash(l, r), b.gethash(l, r)};
	}
	pair<int, int> getfrevhash(int l, int r) 
	{
		return {a.getfrevhash(l, r), b.getfrevhash(l, r)};
	}
};
