#include<iostream>
#include<vector>
#include<utility>
using namespace std;

vector<pair<long long, long long>>Prime_Factorization(long long num)
{
	vector<pair<long long, long long>>Primes;
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			int count = 0;
			while (num % i == 0)
			{
				count++;
				num /= i;
			}
			Primes.push_back({i, count});
		}
	}
	if (num > 1)
	{
		Primes.push_back({num, 1});
	}
	return Primes;
}

int main()
{
	for (pair<long long, long long> prime : Prime_Factorization(26))
		cout << prime.first << " " << prime.second << "\n";
}
