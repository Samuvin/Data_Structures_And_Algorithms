struct Node{
    Node* links[26];
    set<string>dict;
    Node()
    {
        for(int i=0;i<26;i++)
            links[i]=nullptr;
    }
    
    void setNode(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    
    Node* getNode(char ch)
    {
        return links[ch-'a'];
    }
    
    bool Contains(char ch)
    {
        return links[ch-'a']!=nullptr;
    }
    
    void push(string &str)
    {
        dict.insert(str);
    }
    
    set<string> getDict()
    {
        return dict;
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
                node->setNode(word[i],new Node());
            node=node->getNode(word[i]);
            node->push(word);
        }
    }
    set<string> getPrefix(string &word)
    {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->Contains(word[i]))
                return {};
            node=node->getNode(word[i]);
        }
        return node->getDict();
    }
};



class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>>res;
        Trie trie;
        for(int i=0;i<n;i++)
            trie.insert(contact[i]);
        string temp="";
        for(int i=0;i<s.size();i++)
        {
            temp+=s[i];
            set<string>current=trie.getPrefix(temp);
            vector<string>set2;
            if(current.empty())
                res.push_back({"0"});
            else
            {
                while(!current.empty())
                {
                    set2.push_back(*current.begin());
                    current.erase(*current.begin());
                }
                res.push_back(set2);
            }
        }
        return res;
    }
};
