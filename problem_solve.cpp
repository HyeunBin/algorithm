#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int r, c;
string map[751];
int up_left[751][751];
int up_right[751][751];
int down_left[751][751];
int down_right[751][751];

int solve(int y, int x, int size) {
	if (x - size < 0) return -1;
	if (x + size >= c) return -1;
	if (y + 2 * size >= r) return -1;

	if (down_left[y][x] >= size + 1 && down_right[y][x] >= size + 1)
		if (up_left[y + 2 * size][x] >= size + 1 && up_right[y + 2 * size][x] >= size + 1)
			return size;

	return -1;
}

int up_l(int y, int x) {
	if (y < 0 || x < 0 || y >= r || x >= c) return 0;
	if (up_left[y][x] != -1) return up_left[y][x];
	if (map[y][x] == '0') return 0;
	return up_left[y][x] = up_l(y - 1, x - 1) + 1;
}
int up_r(int y, int x) {
	if (y < 0 || x < 0 || y >= r || x >= c) return 0;
	if (up_right[y][x] != -1) return up_right[y][x];
	if (map[y][x] == '0') return 0;
	return up_right[y][x] = up_r(y - 1, x + 1) + 1;
}
int down_l(int y, int x) {
	if (y < 0 || x < 0 || y >= r || x >= c) return 0;
	if (down_left[y][x] != -1) return down_left[y][x];
	if (map[y][x] == '0') return 0;
	return down_left[y][x] = down_l(y + 1, x - 1) + 1;
}
int down_r(int y, int x) {
	if (y < 0 || x < 0 || y >= r || x >= c) return 0;
	if (down_right[y][x] != -1) return down_right[y][x];
	if (map[y][x] == '0') return 0;
	return down_right[y][x] = down_r(y + 1, x + 1) + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> map[i];

	memset(up_left, -1, sizeof(up_left));
	memset(up_right, -1, sizeof(up_right));
	memset(down_left, -1, sizeof(down_left));
	memset(down_right, -1, sizeof(down_right));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == '0') {
				up_left[i][j] = up_right[i][j] = down_left[i][j] = down_right[i][j] = 0;
			}
			else {
				up_left[i][j] = up_l(i, j);
				up_right[i][j] = up_r(i, j);
				down_left[i][j] = down_l(i, j);
				down_right[i][j] = down_r(i, j);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			for (int k = 0; k <= r; k++) {
				int sol = solve(i, j, k) + 1;
				if (sol == -1) break;
				ans = max(ans, sol);
			}
		}
	}
	cout << ans << '\n';
}