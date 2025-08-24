#include <bits/stdc++.h>
using namespace std;

// Reverse polynomial Calculation
struct Rabin_Karp
{
    using ll = long long;
    using RKHash = pair<ll, ll>;

    const ll RADIX_1 = 31;
    const ll RADIX_2 = 29;
    const ll MOD_1 = 1e9 + 7;
    const ll MOD_2 = 1e9 + 33;

    // Convert the character to integer
    ll charToValue(char ch)
    {
        return ch - 'a' + 1;
    }

    // Compute the Hash for a specific string
    RKHash Hash_Value(string &str, ll len)
    {
        ll hash1 = 0, hash2 = 0;
        ll factor1 = 1, factor2 = 1;

        for (int i = len - 1; i >= 0; i--)
        {
            /*
               String = abcde
               Hash = a*(26^4) + b*(26^3) + c*(26^2) + d*(26^1) + e*(26^0)
            */
            hash1 += (charToValue(str[i]) * factor1) % MOD_1;
            factor1 = (factor1 * RADIX_1) % MOD_1;
            hash2 += (charToValue(str[i]) * factor2) % MOD_2;
            factor2 = (factor2 * RADIX_2) % MOD_2;
        }
        return {hash1 % MOD_1, hash2 % MOD_2};
    }

    // Roll the hash value
    ll rollHash(ll stringHash, ll old_char, ll new_char, const ll MOD, ll RADIX, ll MAX_WEIGHT)
    {
        stringHash = (stringHash * RADIX) % MOD;                               // Multiply the current hash by the RADIX
        stringHash = (stringHash - (old_char * MAX_WEIGHT) % MOD + MOD) % MOD; // Remove the old character
        stringHash += (new_char + MOD) % MOD;                                  // Add the new character
        return stringHash % MOD;
    }

    // Compare two hash values
    bool compHash(RKHash &stringHash, RKHash &patHash)
    {
        return (stringHash.first == patHash.first && stringHash.second == patHash.second);
    }

    int rabinKarpDoubleHash(string &str, string &pattern)
    {
        long long strLen = str.size();
        long long patLen = pattern.size();

        if (patLen > strLen)
            return -1;

        long long MAX_WEIGHT_1 = 1;
        long long MAX_WEIGHT_2 = 1;

        // Compute RADIX raised to the power of pat_len.
        // This value is used to remove the contribution of the old character
        // when updating the rolling hash.
        for (long long i = 0; i < patLen; i++)
        {
            MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1;
            MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2;
        }

        // Compute the initial hash values for the pattern and the first window of the text
        RKHash patternHash = Hash_Value(pattern, patLen);
        RKHash stringHash = Hash_Value(str, patLen);

        if (compHash(stringHash, patternHash))
            return 0;

        for (ll i = 1; i <= (strLen - patLen); i++)
        {
            ll old_char = charToValue(str[i - 1]);
            ll new_char = charToValue(str[i + patLen - 1]);

            stringHash.first = rollHash(stringHash.first, old_char, new_char, MOD_1, RADIX_1, MAX_WEIGHT_1);
            stringHash.second = rollHash(stringHash.second, old_char, new_char, MOD_2, RADIX_2, MAX_WEIGHT_2);

            if (compHash(stringHash, patternHash))
                return i;
        }
        return -1;
    }
} RabinKarp;