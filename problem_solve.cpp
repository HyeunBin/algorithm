#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string str;
vector<string> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> str;
	v.push_back(str);
	string s = "";
	for (int i = str.length() - 1; i > 0; i--) {
		s = str[i] + s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++) cout << v[i] << '\n';
}