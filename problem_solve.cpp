#include <iostream>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int num = 0, Mscore = 0;
	for (int i = 1; i <= 5; i++) {
		int score = 0, a;
		for (int j = 0; j < 4; j++) {
			cin >> a;
			score += a;
		}
		if (score > Mscore) {
			Mscore = score;
			num = i;
		}
	}
	cout << num << ' ' << Mscore << '\n';
}