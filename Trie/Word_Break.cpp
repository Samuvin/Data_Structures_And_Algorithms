class Node{
public:
    Node* links[26];
    bool isend;
    Node()
    {
        isend=false;
        for(int i=0;i<26;i++)
            links[i]=nullptr;
    }
    void set(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    bool Contains(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    bool isEnd()
    {
        return isend;
    }
};
class Trie{
Node* root;
public:
    Trie()
    {
        root=new Node();
    }
    void insert(string &str)
    {
        Node* node=root;
        for(int i=0;i<str.size();i++)
        {
            if(!node->Contains(str[i]))
                node->set(str[i],new Node());
            node=node->get(str[i]);
        }
        node->isend=true;
    }
    bool prefix(string &str)
    {
        vector<bool>dp(str.size(),false);
        for(int i=0;i<str.size();i++)
        {
            if(i==0 || dp[i-1])
            {
                Node* node=root;
                for(int j=i;j<str.size();j++)
                {   
                    if(!node->Contains(str[j]))
                        break;
                    node=node->get(str[j]);
                    if(node->isEnd())
                        dp[j]=true;
                }
            }
        }
        return dp[str.size()-1];
    }
};

class Solution {
public:
    vector<int>dp;
    bool solve(int i,string &s,vector<string>&dic)
    {
        if(i>s.size())
            return false;
        if(i==s.size())
            return true;
        if(dp[i]!=-1)
            return dp[i];
        for(string &str:dic)
        {
            int len=str.size();
            if(i+len-1>=s.size())
                continue;
            if(s.substr(i,len)==str && solve(i+len,s,dic))
            {
                return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    //bool wordBreak(string s, vector<string>& dic) 
    //{
    //   dp=vector<int>(s.size(),0);
    //    for(int i=0;i<s.size();i++)
    //    {
    //        for(string &str:dic)
    //        {
    //            int len=str.size();
    //            if(i+1-len<0)
    //            {
    //                continue;
    //            }
    //            if((i-len+1==0) || (dp[i-len]))
    //            {
    //                if(s.substr(i-len+1,len)==str)
    //                    dp[i]=1;
    //            }
    //        }
    //    }
    //    return dp[s.size()-1];
    //}
    bool wordBreak(string s, vector<string>& dic) 
    {
        Trie trie;
        for(string &str:dic)
        {
            trie.insert(str);
        }
        return trie.prefix(s);
    }
};
