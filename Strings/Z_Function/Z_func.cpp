#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> z_func_brute(string &s) {
	vector<int> z(s.size(), 0);

	for (int i = 1; i < s.size(); i++)
	{
		while (z[i] + i < s.size() && s[z[i]] == s[z[i] + i])
		{
			z[i]++;
		}
	}
	return z;
}

vector<int> z_func(string &s)
{
	vector<int> z(s.size(), 0);
	int left = 0, right = 0;

	for (int i = 1; i < s.size(); i++)
	{
		if (i < right)
		{
			z[i] = min(right - i, z[i - left]);
		}
		while (z[i] + i < s.size() && s[z[i]] == s[z[i] + i])
		{
			z[i]++;
		}

		if (i + z[i] > right)
		{
			left = i;
			right = i + z[i];
		}
	}
	return z;
}

int main()
{
	string str;
	cin >> str;
	vector<int> z_brute = z_func_brute(str);
	vector<int> z_optimized = z_func(str);

	cout << "Z-function (brute-force): \n";
	for (int i : z_brute) {
		cout << i << " ";
	}
	cout << "\n";

	cout << "Z-function (optimized): \n";
	for (int i : z_optimized) {
		cout << i << " ";
	}
	cout << "\n";
}
