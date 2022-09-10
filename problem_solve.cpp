#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n-1; i++) cout << ' ';
	cout << "*\n";
	if (n == 1) return 0;
	for (int i = n-2; i > 0; i--) {
		for (int j = 0; j < i; j++) cout << ' ';
		cout << '*';
		for (int j = 0; j < 2 * (n - i - 1) - 1; j++) cout << ' ';
		cout << "*\n";
	}
	for (int i = 0; i < 2 * n - 1; i++)cout << '*';
}
