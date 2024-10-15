#include<iostream>

struct Node {
	Node* child[2];
	Node() {
		child[0] = child[1] = nullptr;
	}
	bool Contains(int bit)
	{
		return child[bit] != nullptr;
	}
	Node* get(int bit)
	{
		return child[bit];
	}
	void set(int bit, Node* node)
	{
		child[bit] = node;
	}
};

class BTrie {
private:
	Node* root;
	int len = 0;
public:
	BTrie(int len)
	{
		root = new Node();
		this->len = len;
	}
	void insert(long long num)
	{
		Node* node = root;
		for (int i = len; i >= 0; i--)
		{
			int bit = (num & (1LL << i)) ? 1 : 0;
			if (!node->Contains(bit))
			{
				node->set(bit, new Node());
			}
			node = node->get(bit);
		}
	}
};
