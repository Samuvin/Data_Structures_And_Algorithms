#include<iostream>
using namespace std;
void toh(int n, char a, char b, char c) {
	if (n == 1) {
		cout << n << "-" << a << "->" << c << "\n";
		return;
	}
	toh(n - 1, a, c, b);
	cout << n << "-" << a << "->" << c << "\n";
	toh(n - 1, b, a, c);
	return;
}

int main() {
	int n;
	cin >> n;
	toh(n, 'a', 'b', 'c');
}
