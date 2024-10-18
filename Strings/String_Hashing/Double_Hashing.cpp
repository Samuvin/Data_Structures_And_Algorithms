#include<bits/stdc++.h>
using namespace std;

struct PolyHasher 
{
	int len, prime, MOD;

	vector<int> powerX, base;

	void init(string s, int _prime, int _MOD)
	{
		prime = _prime;
		MOD = _MOD;

		len = s.length();
		powerX.resize(len + 1);
		base.resize(len + 1);

		base[0] = 0;
		powerX[0] = 1;

		for (int i = 0; i < len; i++) 
		{
			int num = (s[i] - 'a' + 1 ) % MOD;
			base[i + 1] = (1LL * base[i] * _prime + num) % MOD;
			powerX[i + 1] = (1LL * _prime * powerX[i]) % MOD;
		}

	}
	int getHasher(int l, int r) 
	{
		int ans = (base[r + 1] - 1LL * base[l] * powerX[(r - l + 1)]) % MOD;
		return (ans + MOD) % MOD;
	}
};

struct Poly_Double_Hasher 
{
	PolyHasher a, b;
	void init(string s)
	{
		a.init(s, 37, 1000000021);
		b.init(s, 39, 1000000009);
	}
	pair<int, int> getHasher(int l, int r) 
	{
		return {a.getHasher(l, r), b.getHasher(l, r)};
	}
	bool isMatch(int l,int r)
	{
		return a.getHasher(l,r)==b.getHasher(l,r);
	}
};
