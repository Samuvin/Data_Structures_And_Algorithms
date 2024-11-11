#include<iostream>
#include<bits/stdc++.h>
using namespace std;


string s;


void fun(string res, int ind, bool last)
{
	if (ind == s.size())
	{
		cout << res << "\n";
		return;
	}
	int till = (last ? s[ind] - '0' : 9);
	for (int i = 0; i <= till; i++)
	{
		fun(res + to_string(i), ind + 1, last && (i == till));
	}

}



int main()
{
	cin >> s;
	fun("", 0, true);
}
