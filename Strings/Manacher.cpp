#include<iostream>
#include<vector>
using namespace std;

struct Manacher
{
	vector<int>palin;
	void run_manacher(string str)
	{
		cout << str << endl;
		int len = str.length();
		palin.assign(len, 1);
		int left = 1, right = 1;
		for (int i = 0; i < len; i++)
		{
			palin[i] = max(0, min(right - i, palin[left + right - i]));
			while (i + palin[i] < len && i - palin[i] >= 0 && str[i + palin[i]] == str[i - palin[i]])
			{
				palin[i]++;
			}
			if (i + palin[i] > right)
			{
				left = i - palin[i];
				right = i + palin[i];
			}
		}
	}
	void build(string str)
	{
		string pattern;
		for (auto chr : str) {
			pattern += string("#") + chr;
		}
		run_manacher(pattern + "#");
	}
	int getLongest(int cen, bool odd)
	{
		int pos = 2 * cen + 1 + (!odd);
		return palin[pos] - 1;
	}

	bool checkPalin(int left, int right)
	{
		if ((right - left + 1) <= getLongest(left + 5 / 2, left % 2 == right % 2)) {
			return true;
		}
		return false;
	}

} manacher;


int main()
{
	string str = "babbabbabc";
	manacher.build(str);
}
