#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int visited[10000][500];
int map[10000][500];
int dx[3] = { -1,0,1 };
int dy[3] = { 1,1,1 };
bool check; // 가스관 도달여부
int cnt = 0;
int R, C;

void dfs(int a, int b) {
	//cout << "dfs: " << a << " " << endl;
	visited[a][b] = 1;
	if (b == C - 1) {
		cnt++;
		check = true;
		return;
	}
	for (int i = 0; i < 3; i++) {
		int next_x = a + dx[i];
		int next_y = b + dy[i];
		if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C) {
			if (!visited[next_x][next_y] && map[next_x][next_y] != 1) {
				dfs(next_x, next_y);
				if (check) return;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("3109input/plinovod6.txt", "r", stdin);
	cin >> R >> C;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			char c;
			cin >> c;
			if (c == 'x') map[i][j] = 1;
			else map[i][j] = 0;
		}

	for (int i = 0; i < R; i++)
	{
		check = false;
		dfs(i, 0);
	}

	cout << cnt;
}

