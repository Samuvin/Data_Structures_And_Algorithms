class Solution {
public:
    int mini = 0;
    int ind = 0;
    const long long RADIX = 29;
    const long long MOD = 1e9 + 31;
    const long long RADIX1 = 31;
    const long long MOD1 = 1e9 + 7;
    bool Rabin_Karp(string& s, int len) {
        long long hash = 0;
        long long hash1 = 0;

        long long MAX = 1;
        long long MAX1 = 1;
        for (int i = 1; i <= len; i++) {
            MAX = (MAX * RADIX) % MOD;
            MAX1 = (MAX1 * RADIX1) % MOD1;
        }
        for (int i = 0; i < len; i++) {
            hash = (hash * RADIX + (s[i] - 'a' + 1)) % MOD;
            hash1 = (hash1 * RADIX1 + (s[i] - 'a' + 1)) % MOD1;
        }
        set<pair<long long,long long>> hashes;
        hashes.insert({hash,hash1});
        for (int i = 1; i <= (s.size() - len); i++) {
            int old = s[i - 1] - 'a' + 1;
            int newc = s[i + len - 1] - 'a' + 1;
            hash = ((hash * RADIX - old * MAX) + MOD) % MOD;
            hash = (hash + newc + MOD) % MOD;

            hash1 = ((hash1 * RADIX1 - old * MAX1) + MOD1) % MOD1;
            hash1 = (hash1 + newc + MOD1) % MOD1;

            if (hashes.find({hash,hash1}) != hashes.end()) {
                if (len > mini) {
                    mini = len;
                    ind = i;
                }
                return true;
            }
            hashes.insert({hash,hash1});
        }
        return false;
    }
    string longestDupSubstring(string s) {
        string res = "";
        ind = 0;
        mini = 0;
        int lo = 0;
        int hi = s.size();
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (Rabin_Karp(s, mid))
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        if (hi < 0)
            return "";
        return s.substr(ind, hi);
    }
};
