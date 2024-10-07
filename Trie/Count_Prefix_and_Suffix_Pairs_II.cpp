class Node{
public:
    unordered_map<int,Node*>links;
    int count;
    Node()
    {
        count=0;
    }
};
class Solution {
Node* root;
public:
    Solution()
    {
        root=new Node();
    }
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long res=0;
        for(string &str:words)
        {
            int len=str.size();
            Node* node=root;
            for(int i=0;i<str.size();i++)
            {
                int hash=(str[i]*128)+str[len-i-1];
                if(node->links.find(hash)==node->links.end())
                    node->links[hash]=new Node();
                node=node->links[hash];
                res+=node->count;
            }
            node->count+=1;
        }
        return res;
    }
};
