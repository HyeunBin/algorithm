#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int n;
int arr[9];
bool visited[9];

int solve(int num, vector<int> v) {
	if (v.size() == n) {
		int ans = 0;
		for (int i = 0; i < n-1; i++) ans += abs(v[i] - v[i + 1]);
		return ans;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(arr[i]);
			ans = max(ans, solve(num + 1, v));
			v.pop_back();
			visited[i] = false;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	memset(visited, false, sizeof(visited));
	int ans = solve(0, vector<int>());
	cout << ans << '\n';
}