#include<iostream>
using namespace std;

void Bubble_Sort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		bool flag = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = true;
				swap(arr[j], arr[j + 1]);
			}
		}
		if (!flag)
			break;
	}
}


int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	Bubble_Sort(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
