/*
Subset Sum<=x


mask->10101
if 1 take the element
else not take the element

Contraint => Small
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int>SubsestSums(int n, vector<int>a)
{
	vector<int>ans;
	for (int mask = 0; mask < (1 << n); mask++)
	{
		int subsum = 0;
		for (int j = 0; j < n; j++)
		{
			if (mask & (1 << j))
				subsum += a[j];
		}
		ans.push_back(subsum);
	}
	sort(ans.begin(), ans.end());
	return ans;
}


int main()
{
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vector<int>ans = SubsestSums(n, v);
	for (int i : ans)
		cout << i << " ";
}


