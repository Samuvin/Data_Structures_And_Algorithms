#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int k = (*max_element(arr, arr + n)) + 1;
	int count[k];

	memset(count, 0, sizeof(count));

	for (int i = 0; i < n; i++)
		count[arr[i]]++;

	for (int i = 1; i < k; i++)
		count[i] += count[i - 1];


	int output[n];
	for (int i = n - 1; i >= 0; i--)
	{
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	for (int i = 0; i < n; i++)
	{
		arr[i] = output[i];
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
