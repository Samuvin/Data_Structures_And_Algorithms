class Solution {
public:
    vector<int>kmp(string s)
    {
        vector<int>lps(s.size(),0);
        for(int i=1;i<s.size();i++)
        {
            int __prev_match=lps[i-1];
            while(__prev_match>0 && s[__prev_match]!=s[i])
            {
                __prev_match=lps[__prev_match-1];
            }
            lps[i]=__prev_match+(s[__prev_match]==s[i]);
        }
        return lps;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        string s1=a+"#"+s;
        string s2=b+"#"+s;
        vector<int>temp;
        vector<int>v1,v2;
        temp=kmp(s1);
        for(int i=a.size();i<temp.size();i++)
        {
            if(temp[i]==a.size())
            {
                int curr_ind=i-2*a.size();
                if(curr_ind<0)
                    continue;
                v1.push_back(curr_ind);
            }
        }
        temp=kmp(s2);
        for(int i=b.size();i<temp.size();i++)
        {
            if(temp[i]==b.size())
            {
                int curr_ind=i-2*b.size();
                if(curr_ind<0)
                    continue;
                v2.push_back(curr_ind);
            }
        }
        vector<int>res;
        for(int i=0;i<v1.size();i++)
        {
            auto lower=lower_bound(v2.begin(),v2.end(),v1[i])-v2.begin();
            if(lower!=v2.size() && abs(v1[i]-v2[lower])<=k)
                res.push_back(v1[i]);
            else if(lower!=0 && abs(v1[i]-v2[lower-1])<=k)
                res.push_back(v1[i]);
            
        }
        return res;
    }
};
