#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m; 
int a, b;

bool visited[101];
vector<int> v[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> a >> b;
	cin >> m;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	queue<pair<int, int>> q;
	q.push({ a, 0 });
	visited[a] = true;
	int a = -1;
	while (!q.empty()) {
		int now = q.front().first;
		int ans = q.front().second;
		q.pop();
		if (now == b) {
			a = ans;
			break;
		}

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (!visited[next]) {
				q.push({ next, ans + 1 });
				visited[next] = true;
			}
		}
	}
	cout << a << '\n';
}