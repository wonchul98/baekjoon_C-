#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

char map[100][100];
bool visited_1[100][100];
bool visited_2[100][100];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int sx1, sy1, sx2, sy2;
int h, w;
int min_cost = 0;
bool print =true;

void DFS_1(int x, int y, int cost);
void DFS_2(int x, int y, int cost, int cost_by_1);
void solution();
int main() {
	freopen("input/9376_input.txt", "r", stdin);
	int TC;
	cin >> TC;
	while (TC--) {
		/* 초기화 */
		sx1 = -1; sx2 = -1; sy1 = -1; sy2 = -1;
		min_cost = 987654321;
		cin >> h >> w;
		if (print) printf("h: %d, w: %d\n", h, w);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				visited_1[i][j] = false;
				visited_2[i][j] = false;
				cin >> map[i][j];
				if (map[i][j] == '$') {
					map[i][j] = '.';
					if (sx1 == -1) { 
						sx1 = i;
						sy1 = j;
					}
					else {
						sx2 = i;
						sy2 = j;
					}
				}
			}
		}
	}
	solution();
	return 0;
}

void solution(){
	DFS_1(sx1, sy1, 0);
	cout << min_cost << endl;
}

void DFS_1(int x, int y, int cost) {
	visited_1[x][y] = true;
	if (print) printf("DFS_1(%d, %d, %d)\n", x, y, cost);
	if (x == 0 || x == h - 1 || y == 0 || y == w - 1) {
		DFS_2(sx2, sy2, cost, cost);
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (map[nx][ny] == '.' && !visited_1[nx][ny]) {
			DFS_1(nx, ny, cost);
		}
		else if (map[nx][ny] == '#' && !visited_1[nx][ny]) {
			map[nx][ny] = '.';
			DFS_1(nx, ny, cost+1);
			map[nx][ny] = '#';
		}
	}
	visited_1[x][y] = false;
	return;
}
void DFS_2(int x, int y, int cost, int cost_by_1) {
	visited_2[x][y] = true;
	if (print) printf("DFS_2(%d, %d, %d, %d)\n", x, y, cost, cost_by_1);
	if (visited_1[x][y]) {
		cout << " 동선 겹침!" << endl;
		cost += cost_by_1;
		min_cost = min(cost, min_cost);
		if (print)cout << "min_cost: " << min_cost << endl;
		return;
	}
	if (x == 0 || x == h - 1 || y == 0 || y == w - 1) {
		min_cost = min(cost, min_cost);
		if(print)cout << "min_cost: " << min_cost << endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (map[nx][ny] == '.' && !visited_2[nx][ny]) {
			DFS_2(nx, ny, cost, cost_by_1);
		}
		else if (map[nx][ny] == '#' && !visited_2[nx][ny]) {
			map[nx][ny] = '.';
			DFS_2(nx, ny, cost+1, cost_by_1);
			map[nx][ny] = '#';
		}
	}
	visited_2[x][y] = false;
	return;
}