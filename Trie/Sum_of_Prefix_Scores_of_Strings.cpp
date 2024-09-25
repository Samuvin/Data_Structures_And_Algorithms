struct Node{
    Node* links[26];
    int prefix=0;
    
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

    void inc()
    {
        prefix++;
    }

    int pref()
    {
        return prefix;
    }
};
class Trie{
private:
    Node* root;
public:
    Trie()
    {
        root=new Node();
    }
    void insert(string &word)
    {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->Contains(word[i]))
            {
                node->set(word[i],new Node());
            }
            node=node->get(word[i]);
            node->inc();
        }
    }
    int prefix(string &word)
    {
        Node* node=root;
        int res=0;
        for(int i=0;i<word.size();i++)
        {
            node=node->get(word[i]);
            res+=node->pref();
        }
        return res;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& word) {
        vector<int>res;
        Trie trie;
        for(int i=0;i<word.size();i++)
        {
            trie.insert(word[i]);
        }
        for(int i=0;i<word.size();i++)
        {
            res.push_back(trie.prefix(word[i]));
        }
        return res;
    }
};
