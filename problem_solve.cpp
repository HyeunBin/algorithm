#include <iostream>
#include <vector>

using namespace std;

int n;
bool visited[9];

void solve(int idx, vector<int> v) {
	if (idx == n) {
		for (int i = 0; i < n; i++) cout << v[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(i);
			solve(idx + 1, v);
			visited[i] = false;
			v.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)visited[i] = false;
	solve(0, vector<int>());
}