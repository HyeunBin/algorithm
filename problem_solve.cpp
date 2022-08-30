#include <iostream>

using namespace std;

int n, m;
int parent[1000002];

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	parent[u] = v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0) merge(b, c);
		else {
			if (find(b) == find(c)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}
}