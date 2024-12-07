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

	int index = 0;
	for (int element = 0; element < k; element++)
	{
		for (int cnt = 1; cnt <= count[element]; cnt++)
			arr[index++] = element;
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
