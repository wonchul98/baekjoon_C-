#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int visitedarr[10005][505];
int dx[3] = { -1,0,1 };
int dy = 1;
int R, C, cnt = 0;
stack<int, int> now;
stack<int, int> will;
stack<int, int> S;

bool visited(int a, int b);
void print_arr(int R, int C);
void dfs(int a ,int b);

int main() {
	freopen("input.txt", "r", stdin);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char input;
			cin >> input;
			if (input == 'x') visitedarr[i][j] = 1;
		}
	}
	for (int i = 0; i < R; i++) {
		now.push(make_pair(i, 0));
		dfs(i, 0);
		while (!now.empty()) now.pop();
		while (!will.empty()) will.pop();
		while (!S.empty())S.pop();
	}
	return 0;
}

bool visited(int a, int b) {
	if (visitedarr[a][b] == 1) return true;
	else return false;
}

void print_arr(int R, int C) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << visitedarr[i][j] << " ";
		}
		cout << endl;
	}
}

void dfs(int a, int b) {
	cout << "dfs(" << a << "," << b << ")" << endl;
	if (b == C - 1) { cnt++; return; }
	int nx = a;
	int ny = b;
	bool flag = false;
	for (int i = 0; i < 3; i++) {
		if (!visited(nx + dx[i], ny + dy) && nx + dx[i] > -1 && nx + dx[i] < R) {
			nx += dx[i];
			ny += dy;
			if (!flag) {
				flag = true;
				now.push(make_pair(nx, ny));
				dfs(nx, ny);
			}
			else S.push(make_pair(nx, ny));
		}
	}
	while (!S.empty()) {
		will.push(make_pair(S.top().first(), S.top().second));
		S.pop();
	}
	if (!flag) { //진행하지 못하는 경우 back_tracking
		if (will.empty()) { return; }//back_tracking이 안되는 경우 return
		now.pop();
		nx = will.top().first();
		ny = will.top().second();
		will.pop();
		now.push(make_pair(nx, ny));
		dfs(nx, ny);
	}
}