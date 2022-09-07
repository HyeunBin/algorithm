#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string str;

bool solve(int s, int e) {
	if (s >= e) return true;
	if (str[s] == str[e]) return solve(s + 1, e - 1);
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> str;
	if (solve(0, str.length() - 1))cout << 1 << '\n';
	else cout << 0 << '\n';
}