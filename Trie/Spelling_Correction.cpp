
/*
Implement a Spelling Correction Mechanism

Given a set of String Answer Q queries of the form

? S K : Find all Strings in set that have atmost K possition mismatch with S
*/

#include<iostream>
#include<vector>
using namespace std;


const long long int MAX_LIMIT = 26;

struct Node {

	Node* links[MAX_LIMIT];
	int count;
	Node()
	{
		for (int i = 0; i < MAX_LIMIT; i++)
		{
			links[i] = nullptr;
		}
		count = 0;
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
		count++;
	}

	int end()
	{
		return count;
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

	void DFS(Node* node, string &s, int pos, int k, string &str, vector<string>&res)
	{
		if (k < 0)
			return;

		if (pos == s.size())
		{
			for (int i = 0; i < node->end(); i++)
				res.push_back(str);
			return;
		}

		for (int i = 0; i < MAX_LIMIT; i++)
		{
			char ch = 'a' + i;
			if (node->contains(ch))
			{
				str += ch;
				DFS(node->getNode(ch), s, pos + 1, k - (ch != s[pos]), str, res);
				str.pop_back();
			}
		}
	}
	vector<string> searchMatch(string &s, int k)
	{
		vector<string>res;
		string current;
		DFS(root, s, 0, k, current, res);
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

	int q;
	cin >> q;
	string misMatch;
	cin >> misMatch;
	while (q--)
	{
		int k;
		cin >> k;
		vector<string>res = trie.searchMatch(misMatch, k);
		for (string &str : res)
			cout << str << " ";
		if (res.size() == 0)
			cout << "-1";
		cout << "\n";
	}

}
