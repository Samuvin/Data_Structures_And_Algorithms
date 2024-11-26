//https://www.geeksforgeeks.org/problems/unique-rows-in-boolean-matrix/1

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

struct Node
{
    Node* links[2];
    Node()
    {
        links[0]=links[1]=nullptr;
    }
    void setNode(int ch,Node* node)
    {
        links[ch]=node;
    }
    
    Node* getNode(int ch)
    {
        return links[ch];
    }
    
    bool Contains(int ch)
    {
        return links[ch]!=nullptr;
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
    bool insert(int M[MAX][MAX],int row,int col)
    {
        bool flag=false;
        Node* node=root;
        for(int i=0;i<col;i++)
        {
            if(!node->Contains(M[row][i]))
            {
                flag=true;
                node->setNode(M[row][i],new Node());
            }
            node=node->getNode(M[row][i]);
        }
        return flag;
    }
};


class Solution
{
    public:
    
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        Trie trie;
        vector<vector<int>>res;
        for(int i=0;i<row;i++)
        {
            bool isPos=trie.insert(M,i,col);
            if(isPos)
            {
                vector<int>temp;
                for(int j=0;j<col;j++)
                {
                    temp.push_back(M[i][j]);
                }
                res.push_back(temp);
            }
        }
        return res;
    }
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    
cout << "~" << "\n";
}
}
