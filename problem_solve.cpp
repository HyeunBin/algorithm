#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
string str = "";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin.ignore();
	for (int test = 0; test < n; test++) {
		getline(cin, str);
		string s = "";
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ') {
				reverse(s.begin(), s.end());
				cout << s << ' ';
				s = "";
			}
			else s += str[i];
		}
		reverse(s.begin(), s.end());
		cout << s << '\n';
	}
}
