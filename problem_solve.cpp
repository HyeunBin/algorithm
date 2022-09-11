#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int r, c;
string map[51];
pair<int, int> d, s;
vector<pair<int, int>> water;
bool visited[51][51];

int dy[] = { 0, -1, 0, 1 };
int dx[] = { 1, 0, -1, 0 };

void watering() {
	int size = water.size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 4; j++) {
			int ny = water[i].first + dy[j];
			int nx = water[i].second + dx[j];

			if (0 <= ny && ny < r && 0 <= nx && nx < c) {
				if (!visited[ny][nx] && map[ny][nx] != 'D' && map[ny][nx] != 'X') {
					visited[ny][nx] = true;
					water.push_back({ ny, nx });
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(visited, false, sizeof(visited));

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> map[i];
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'D') d.first = i, d.second = j;
			else if (map[i][j] == 'S') s.first = i, s.second = j;
			else if (map[i][j] == '*') {
				water.push_back({ i, j });
				visited[i][j] = true;
			}
		}
	}

	queue < pair<int, pair<int, int>>> q;
	q.push({ 0, {s.first, s.second} });
	visited[s.first][s.second] = true;
	int ans = -1;
	while (!q.empty()) {
		watering();
		cout << q.size() << ' ' << water.size() << '\n';
		for (int test = 0; test < q.size(); test++) {
			int time = q.front().first;
			int y = q.front().second.first;
			int x = q.front().second.second;
			q.pop();
			if (y == d.first && x == d.second) {
				ans = time;
				break;
			}

			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j];
				int nx = x + dx[j];

				if (0 <= ny && ny < r && 0 <= nx && nx < c) {
					if (!visited[ny][nx] && map[ny][nx] != 'X') {
						visited[ny][nx] = true;
						q.push({ time + 1, {ny, nx} });
					}
				}
			}
		}
	}
	if (ans == -1) cout << "KAKTUS" << '\n';
	else cout << ans << '\n';
}