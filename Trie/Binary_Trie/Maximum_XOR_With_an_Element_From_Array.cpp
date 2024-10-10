//https://www.naukri.com/code360/problems/max-xor-queries_1382020?leftPanelTabValue=PROBLEM
#include<algorithm>
struct Node{
	Node* links[2];
	Node()
	{
		links[0]=links[1]=nullptr;
	}
	Node* get(int bit)
	{
		return links[bit];
	}
	void set(int bit,Node* node)
	{
		links[bit]=node;
	}
	bool Contains(int bit)
	{
		return links[bit]!=NULL;
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
	void insert(int num)
	{
		Node* node=root;
		for(int i=31;i>=0;i--)
		{
			int mask=(num>>i)&1;
			if(!node->Contains(mask))
				node->set(mask,new Node());
			node=node->get(mask);
		}
	}
	int prefix(int num)
	{
		Node* node=root;
		int res=0;
		for(int i=31;i>=0;i--)
		{
			int mask=(num>>i)&1;
			if(node->Contains(1-mask))
			{
				res=res|(1<<i);
				node=node->get(1-mask);
			}
			else
				node=node->get(mask);
		}
		return res;
	}
};


vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &qr){
	int len=qr.size();
	vector<int>res(len);
	iota(res.begin(),res.end(),0);
	sort(res.begin(),res.end(),[&](int a,int b){
		return qr[a][1]<=qr[b][1];
	});
	sort(arr.begin(),arr.end());
	int ind=0;
	Trie trie;
	vector<int>ans(len);
	for(int i=0;i<len;i++)
	{

		int Qind=res[i];
		int ai=qr[Qind][1];
		int xi=qr[Qind][0];
		while(ind<arr.size() && arr[ind]<=ai)
		{
			trie.insert(arr[ind]);
			ind++;
		}
		if(ind==0)
			ans[Qind]=-1;
		else
			ans[Qind]=trie.prefix(xi);
	}
	return ans;
}
