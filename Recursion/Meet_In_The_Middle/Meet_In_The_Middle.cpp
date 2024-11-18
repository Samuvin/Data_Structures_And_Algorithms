/*
Subset Sum<=x


mask->10101
if 1 take the element
else not take the element

Contraint => Large
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

void Meet_In_The_Middle(int n, vector<int>&arr, int Target)
{
	vector<int>A, B;
	for (int i = 0; i < arr.size(); i++)
	{
		if (i % 2)
			A.push_back(arr[i]);
		else
			B.push_back(arr[i]);
	}
	auto Sa = SubsestSums(A.size(), A);
	auto Sb = SubsestSums(B.size(), B);
	long long res = 0;
	for (auto v : Sa)
	{
		res += upper_bound(Sb.begin(), Sb.end(), Target - v) - Sb.begin();
	}
	cout << res << " ";

}

int main()
{
	int n, tar;
	cin >> n >> tar;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	Meet_In_The_Middle(n, v, tar);
}


