class Solution {
public:
    const long long RADIX_1 = 29;
    const long long RADIX_2 = 27;
    const long long MOD_1 = 1000000009;
    const long long MOD_2 = 1000000021;

    pair<long long, long long> Hash_Value(string &str, long long len) {
        long long hash1 = 0, hash2 = 0;

        for (int i = 0; i < len; i++) {
            int value = (str[i]-'A'+3);
            hash1 = (hash1 * RADIX_1 + value) % MOD_1;
            hash2 = (hash2 * RADIX_2 + value) % MOD_2;
        }
        return {hash1, hash2};
    }

    vector<string> Rabin_Karp_Double_Hash(string &str) {
        vector<string> res;
        long long str_len = str.size();
        long long pat_len = 10;
        if (pat_len > str_len) return {};

        long long MAX_WEIGHT_1 = 1;
        long long MAX_WEIGHT_2 = 1;

        for (long long i = 0; i < pat_len; i++) {
            MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1;
            MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2;
        }

        pair<long long, long long> String_Hash = Hash_Value(str, pat_len);
        map<pair<long long, long long>, int> mp;
        mp[String_Hash] = 1;

        for (long long i = 1; i <= (str_len - pat_len); i++) {
            int old_value = (str[i - 1]-'A'+3);
            int new_value = (str[i + pat_len - 1]-'A'+3);

            String_Hash.first = ((String_Hash.first * RADIX_1 - old_value * MAX_WEIGHT_1)%MOD_1 + MOD_1) % MOD_1;
            String_Hash.first = (String_Hash.first + new_value) % MOD_1;

            String_Hash.second = ((String_Hash.second * RADIX_2 - old_value * MAX_WEIGHT_2)%MOD_2 + MOD_2) % MOD_2;
            String_Hash.second = (String_Hash.second + new_value) % MOD_2;

            if (mp[String_Hash] == 1) {
                res.push_back(str.substr(i, pat_len));
            }

            mp[String_Hash]++;
        }

        return res;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        return Rabin_Karp_Double_Hash(s);
    }
};
