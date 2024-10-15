struct Node
{
	Node* child[2];
	int count;
	Node()
	{
		child[0] = child[1] = nullptr;
		count = 0;
	}
	Node* get(int bit)
	{
		return child[bit];
	}
	void set(int bit, Node* node)
	{
		child[bit] = node;
	}
	bool Contains(int bit)
	{
		return child[bit] != nullptr;
	}
	void increment()
	{
		count++;
	}
	void decrement()
	{
		count--;
	}
};
class BTrie
{
private:
	Node* root;
	int length = 0;
public:
	BTrie(int length)
	{
		root = new Node();
		this->length = length;
	}
	void insert(int val)
	{
		Node* node = root;
		for (int i = length; i >= 0; i--)
		{
			int bit = (val & (1LL << i)) ? 1 : 0;
			if (!node->Contains(bit))
			{
				node->set(bit, new Node());
			}
			node = node->get(bit);
			node->increment();
		}
	}
	void remove(int val)
	{
		Node* node = root;
		Node* previous = root;
		for (int i = length; i >= 0; i--)
		{
			int bit = (val & (1LL << i)) ? 1 : 0;
			node = node->get(bit);
			node->decrement();
			if (node->count == 0)
			{
				previous->set(bit, nullptr);
			}
			previous = node;
		}
	}
	int getMax(int val)
	{
		Node* node = root;
		int res = 0;
		for (int i = length; i >= 0; i--)
		{
			int bit = ((val & (1LL << i)) ? 1 : 0);
			if (node->Contains(1 - bit))
			{
				res |= (1LL << i);
				node = node->get(1 - bit);
			}
			else if (node->Contains(bit))
			{
				node = node->get(bit);
			}
		}
		return res;
	}
};

class Solution {
public:
	int maximumStrongPairXor(vector<int>& vals)
	{
		int lo = 0;
		int length = vals.size();
		int res = 0;
		sort(vals.begin(), vals.end());
		BTrie trie(31);
		for (int i = 0; i < length; i++)
		{
			while (lo < i && abs(vals[lo] - vals[i]) > vals[lo])
			{
				trie.remove(vals[lo]);
				lo++;
			}
			res = max(res, trie.getMax(vals[i]));
			trie.insert(vals[i]);
		}
		return res;
	}
};
