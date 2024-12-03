#include<iostream>
#include<vector>
using namespace std;


const long long int MAX_LIMIT = 26;

struct Node {

	Node* links[MAX_LIMIT];
	bool isEnd;
	Node()
	{
		for (int i = 0; i < MAX_LIMIT; i++)
		{
			links[i] = nullptr;
		}
		isEnd = false;
	}

	bool contains(char ch)
	{
		return links[ch - 'a'];
	}

	void setNode(char ch, Node* node)
	{
		links[ch - 'a'] = node;
	}

	Node* getNode(char ch)
	{
		return links[ch - 'a'];
	}

	void setEnd()
	{
		isEnd = true;
	}

	bool end()
	{
		return isEnd;
	}
};

class Trie {
private:
	Node* root;
public:
	Trie()
	{
		root = new Node();
	}
	void insert(string &word)
	{
		Node* node = root;
		for (int i = 0; i < word.size(); i++)
		{
			if (!node->contains(word[i]))
				node->setNode(word[i], new Node());
			node = node->getNode(word[i]);
		}
		node->setEnd();
	}
	void DFS(Node* node, vector<string>&result, string &str)
	{
		if (node->end())
		{
			result.push_back(str);
		}
		for (int i = 0; i < MAX_LIMIT; i++)
		{
			char ch = 'a' + i;
			if (node->contains(ch))
			{
				str += ch;
				DFS(node->getNode(ch), result, str);
				str.pop_back();
			}
		}
	}
	vector<string> Lexi_Order()
	{
		Node* node = root;
		vector<string>res;
		string current = "";
		DFS(node, res, current);
		return res;
	}
};

int main()
{
	int n;
	cin >> n;
	vector<string>dict(n);
	for (int i = 0; i < n; i++)
		cin >> dict[i];
	Trie trie;
	for (string &str : dict)
		trie.insert(str);

	vector<string>result = trie.Lexi_Order();
	for (string &str : result)
		cout << str << " ";
}
