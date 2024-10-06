const long long int MOD=1e9+7;
class Solution {
public:
    long long Hash_Value(string &str,long long RADIX,long long pat_len)
    {
        long long ans=0;
        long long factor=1;
        for(long long i=pat_len-1;i>=0;i--)
        {
            ans+=((str[i]-'a')*factor)%MOD;
            factor=(factor * RADIX)%MOD;
        }
        return ans%MOD;
    }
    long long Rabin_Karp_Single_Hash(string &str,string &pattern)
    {
        long long str_len=str.size(),pat_len=pattern.size();
        if(str_len<pat_len)
            return -1;

        long long RADIX=26;
        long long MAX_WEIGHT=1;

        for(long long i=1;i<=pat_len;i++)
        {
            MAX_WEIGHT=(MAX_WEIGHT*RADIX)%MOD;
        }

        long long Hash_Pattern=Hash_Value(pattern,RADIX,pat_len);
        long long Hash_String=0;
        
        for(long long i=0;i<=(str_len-pat_len);i++)
        {
            if(i==0)
            {
                Hash_String=Hash_Value(str,RADIX,pat_len);
            }
            else
            {
               Hash_String = ((Hash_String * RADIX) % MOD - ((str[i-1] - 'a') * MAX_WEIGHT) % MOD + (str[i + pat_len - 1] - 'a') + MOD) % MOD;

            }

            if(Hash_String == Hash_Pattern)
            {
                for(int j=0;j<pat_len;j++)
                {
                    if(str[i+j]!=pattern[j])
                        break;
                    if(j==pat_len-1)
                        return i;
                }
            }
        }
        return -1;
    }


    int strStr(string haystack, string needle) {
        return Rabin_Karp_Single_Hash(haystack,needle);
    }
};
