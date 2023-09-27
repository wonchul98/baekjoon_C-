#include<iostream>
#include<vector>

using namespace std;
int N;
int cnt = 0;
int map[17][17] = {0,};
bool print = false;
void dfs(int x, int y, int position);

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	dfs(N, N, 1);
	dfs(N, N, 2);
	dfs(N, N, 3);
	cout << cnt << endl;
	return 0;
}
void dfs(int x, int y, int position){
	if (position == 2 && (map[x - 1][y] == 1 || map[x][y - 1] || x - 1 <= 0 || y - 1 <= 0)) return;
	if (print) printf("dfs(%d,%d,%d)\n", x, y, position);
	if (map[x][y] == 1 || x <= 0 || x > N || y <= 0 || y > N) return;
	if (x == 1 && y == 2 && position == 3) {
		cnt += 1;
		return;
	}
	switch (position) {
	case 1: {
		dfs(x - 1, y, 1);
		dfs(x - 1, y, 2);
		break;
	}
	case 2: {
		dfs(x - 1, y - 1, 1);
		dfs(x - 1, y - 1, 2);
		dfs(x - 1, y - 1, 3);
		break;
	}
	case 3: {
		dfs(x, y - 1, 2);
		dfs(x, y - 1, 3);
		break;
	}
	}

}

