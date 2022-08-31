#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int ans = 0, sum = 0;
	int start = 0, end = 0;
	while (end <= n) {
		if (sum == m) {
			ans++;
			sum -= arr[start++];
		}
		else if (sum > m) {
			sum -= arr[start++];
		}
		else {
			sum += arr[end++];
		}
		//cout << start << ' ' << end << ' ' << sum << '\n';
	}
	cout << ans << '\n';
}