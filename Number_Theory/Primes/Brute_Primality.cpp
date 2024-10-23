#include<iostream>
using namespace std;

bool isPrime(long long num)
{
	if (num <= 1)
		return false;
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

int main()
{
	cout << isPrime(13);
}
