class Solution {
public:
    vector<int>kmp(string s)
    {
        vector<int>lps(s.size(),0);
        for(int i=1;i<s.size();i++)
        {
            int prev=lps[i-1];
            while(prev>0 && s[prev]!=s[i])
                prev=lps[prev-1];
            lps[i]=prev+(s[prev]==s[i]);
        }
        return lps;
    }
    int minValidStrings(vector<string>& words, string target) {
        vector<vector<int>>lps;
        for(int i=0;i<words.size();i++)
            lps.push_back(kmp(words[i]+"#"+target));
        int res=0;
        int len=target.size();
        while(len>0)
        {
            int match=0;
            for(int i=0;i<words.size();i++)
            {
                match=max(match,lps[i][words[i].size()+len]);
            }
            if(match==0)
                return -1;
            res++;
            len-=match;
        }
        return res;
    }
};
