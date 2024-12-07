#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

void countingSort(int arr[], int n, int exp)
{
	int count[10] = {0};
	int output[n];


	for (int i = 0; i < n; i++) {
		count[(arr[i] / exp) % 10]++;
	}

	for (int i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		int digit = (arr[i] / exp) % 10;
		output[count[digit] - 1] = arr[i];
		count[digit]--;
	}

	for (int i = 0; i < n; i++) {
		arr[i] = output[i];
	}
}


void radixSort(int arr[], int n)
{
	int maxi = arr[0];
	for (int i = 1; i < n; i++) {
		maxi = max(maxi, arr[i]);
	}
	for (int exp = 1; maxi / exp > 0; exp *= 10) {
		countingSort(arr, n, exp);
	}
}


int main()
{
	int n;
	cin >> n;
	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	radixSort(arr, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}
