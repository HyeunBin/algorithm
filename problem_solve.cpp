#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int v, e;
int color[20001];
vector<int> graph[20001];

void bfs(int first) {
	queue<pair<int, int>> q;
	q.push({ first, 0 });
	color[first] = 0;
	while (!q.empty()) {
		int now = q.front().first;
		int now_color = q.front().second;
		q.pop();

		int next_color = (now_color == 0 ? 1 : 0);
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			if (color[next] == -1) {
				color[next] = next_color;
				q.push({ next, next_color });
			}
		}
	}
}

bool solve() {
	for (int now = 1; now <= v; now++) {
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			if (color[now] == color[next]) {
				return false;
			}
		}
	}
	return true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int test;
	cin >> test;
	while (test-- > 0) {
		memset(color, -1, sizeof(color));
		cin >> v >> e;
		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		for (int i = 1; i <= v; i++) {
			if (color[i] == -1) bfs(i);
		}
		if (solve()) cout << "YES" << '\n';
		else cout << "NO" << '\n';

		for (int i = 1; i <= v; i++) graph[i].clear();
	}
}