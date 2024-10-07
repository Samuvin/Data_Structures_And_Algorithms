class Node{
public:
    Node* links[26];
    bool isEnd;
    Node()
    {
        isEnd=false;
        for (int i = 0; i < 26; i++) 
            links[i] = nullptr;
    }
    bool Contains(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void set(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
};
class WordDictionary {
Node* root;
public:
    WordDictionary() {
        root=new Node();
    }
    void addWord(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->Contains(word[i]))
                node->set(word[i],new Node());
            node=node->get(word[i]);
        }   
        node->isEnd=true;
    }
    
    bool dfs(string word,int ind,Node* node)
    {
        Node* curr=node;
        for(int i=ind;i<word.size();i++)
        {
            if(word[i]=='.')
            {
                for(int j=0;j<26;j++)
                {
                    if(curr->links[j]!=NULL)
                    {
                        if(dfs(word,i+1,curr->links[j]))
                            return true;
                    }
                }
                return false;
            }
            else
            {
                if(!curr->Contains(word[i]))
                    return false;
            }
            curr=curr->get(word[i]);
        }
        return curr->isEnd;
    }

    bool search(string word) 
    {
        return dfs(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
