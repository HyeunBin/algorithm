#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int c[11];
vector<pair<int, int>> v[11];
bool visited[11];

int solve(int num) {
	if (num == n) return 0;

	int ans = 987654321;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			for (int j = 0; j < v[i].size(); j++) {
				c[v[i][j].first] -= v[i][j].second;
			}
			ans = min(ans, solve(num + 1) + (c[i] > 0 ? c[i] : 1));
			for (int j = 0; j < v[i].size(); j++) {
				c[v[i][j].first] += v[i][j].second;
			}
			visited[i] = false;
		}
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		visited[i] = false;
	}
	for (int i = 1; i <= n; i++) {
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;
			v[i].push_back({ a, b });
		}
	}

	int ans = solve(0);
	cout << ans << '\n';
}