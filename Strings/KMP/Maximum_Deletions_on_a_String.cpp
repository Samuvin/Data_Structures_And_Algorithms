class Solution {
public:
    vector<int> kmp(string &s, int start) 
    {
        int n = s.size() - start; 
        vector<int> lps(n, 0);  
        vector<int> res;
        for (int i = 1; i < n; i++) 
        {
            int prev = lps[i - 1];
            while (prev && s[start + prev] != s[start + i])
                prev = lps[prev - 1];
            lps[i] = prev + (s[start + prev] == s[start + i]);
            if (i == 2 * lps[i] - 1)
                res.push_back(lps[i]);
        }
        return res; 
    }
    int deleteString(string s) 
    {
        int n=s.size();
        vector<int> dp(n + 1, 1);
        for (int i = n - 1; i >= 0; i--) 
        {
            for (int len : kmp(s, i)) 
            {
                dp[i] = max(dp[i], dp[i + len] + 1);
            }
        }
        return dp[0];
    }
};
