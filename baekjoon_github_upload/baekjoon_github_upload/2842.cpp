#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
bool print = false;
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
char map[50][50];
int D_cost[50][50];
bool visited[50][50];
int N, cnt = 0, s_x, s_y;
int min_cost = 987654321;
void DFS(int x, int y, int big, int small, int count);
int main() {
	freopen("input/2842_input.txt","r", stdin);
	cin >> N;
	if (print) cout << "N: " <<  N << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char input;
			cin >> input;
			map[i][j] = input;
			if (input == 'K') cnt++;
			if (input == 'P') { s_x = i; s_y = j; }
			visited[i][j] = false;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;
			D_cost[i][j] = input;
		}
	}
	visited[s_x][s_y] = true;
	DFS(s_x, s_y, 0, 987654321, 0);
	cout << min_cost << endl;
	return 0;
}

void DFS(int x, int y, int big, int small, int count) {
	if (print) printf("DFS(%d, %d, %d, %d, %d)\n", x, y, big, small, count);
	if (print) cout << "now: " << D_cost[x][y] << endl;
	int n_big = max(D_cost[x][y], big); //
	int n_small = min(D_cost[x][y], small);
	int n_cost = n_big - n_small;
	if (n_cost > min_cost) { if (print) cout << "너무커서 pass" << endl; return; }
	if (map[x][y] == 'K') {
		count++;
		if (count == cnt) {//마지막 집이면
			if (print) cout << "~~~~~찾았다~~~~~" << endl;
			if (print) cout << "cost: " << n_cost << endl;
			min_cost = min(min_cost, n_cost);
			if (print) cout << "min_cost: " << min_cost << endl;
			return;
		}
	}
	for (int i = 0; i < 8; i++) {
		int n_x = x + dx[i];
		int n_y = y + dy[i];
		if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N) continue;
		if (visited[n_x][n_y])continue; //방문한 곳이면 pass
		visited[n_x][n_y] = true;
		DFS(n_x, n_y, n_big, n_small, count);
		visited[n_x][n_y] = false;
	}
}