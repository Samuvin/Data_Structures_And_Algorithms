#include<bits/stdc++.h>
using namespace std;

struct Rabinn_Karp
{

	const long long RADIX_1 = 31;
	const long long RADIX_2 = 29;
	const long long MOD_1 = 1e9 + 7;
	const long long MOD_2 = 1e9 + 33;

	long long charToValue(char ch)
	{
		return ch - 'a' + 1;
	}

	pair<long long, long long> Hash_Value(string &str, long long len)
	{
		long long hash1 = 0, hash2 = 0;
		long long factor1 = 1, factor2 = 1;

		for (int i = 0; i < len; i++)
		{
			hash1 = (hash1 * RADIX_1 + charToValue(str[i])) % MOD_1;
			hash2 = (hash2 * RADIX_2 + charToValue(str[i])) % MOD_2;
		}
		return {hash1, hash2};
	}

	int Rabin_Karp_Double_Hash(string &str, string &pattern)
	{
		long long str_len = str.size();
		long long pat_len = pattern.size();

		if (pat_len > str_len) return -1;

		long long MAX_WEIGHT_1 = 1;
		long long MAX_WEIGHT_2 = 1;

		for (long long i = 0; i < pat_len; i++)
		{
			MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1;
			MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2;
		}

		pair<long long, long long> Pattern_Hash = Hash_Value(pattern, pat_len);
		pair<long long, long long> String_Hash = Hash_Value(str, pat_len);

		if (String_Hash.first == Pattern_Hash.first && String_Hash.second == Pattern_Hash.second)
			return 0;

		for (long long i = 1; i <= (str_len - pat_len); i++)
		{
			long long old_char = charToValue(str[i - 1]);
			long long new_char = charToValue(str[i + pat_len - 1]);

			String_Hash.first = (String_Hash.first * RADIX_1 - old_char * MAX_WEIGHT_1 + MOD_1) % MOD_1;
			String_Hash.first = (String_Hash.first + new_char + MOD_1) % MOD_1;

			String_Hash.second = (String_Hash.second * RADIX_2 - old_char * MAX_WEIGHT_2 + MOD_2) % MOD_2;
			String_Hash.second = (String_Hash.second + new_char + MOD_2) % MOD_2;

			if (String_Hash.first == Pattern_Hash.first && String_Hash.second == Pattern_Hash.second)
				return i;
		}
		return -1;
	}
} RabinKarp;

int main()
{
	string str = "helloworld";
	string pattern = "world";
	cout << RabinKarp.Rabin_Karp_Double_Hash(str, pattern);
}
