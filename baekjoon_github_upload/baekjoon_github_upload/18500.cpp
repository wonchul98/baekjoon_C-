#define INF 987654321
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

vector<pair<int, int>> del;
vector<pair<int, int>> make;

int R, C, N;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool print = true;
bool connected = false;

char map[101][101];
bool visited[101][101] = {false,};
void dfs(int x, int y);
void go_down();
void print_map();
void get_min_dist();
int min_dist = INF;
int main() {
	cin >> R >> C;
	for (int i = 0; i <= R; i++) {
		for (int j = 0; j <= C; j++)
			map[i][j] = '.';
	}
	for (int i = 1; i <= R; i++) {
		string input;
		cin >> input;
		for (int j = 1; j <= C; j++) {
			map[i][j] = input[j - 1];
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		connected = false;
		while (!del.empty()) del.pop_back();
		while (!make.empty()) make.pop_back();
		min_dist = INF;
		int h, start;
		cin >> h;
		h = R - h + 1;
		if (i % 2 == 0) start = 1;
		else  start = C;
		while (map[h][start] != 'x' && start > 0 && start <= C) {
			if (i % 2 == 0) start += 1;
			else start -= 1;
			if (print) cout << "start: " << start << endl;
		}
		//if (i % 2 == 0) start += 1;
		//else start -= 1;
		if (start <= 0 || start > C) continue;
		if (i % 2 == 0 && map[h][start] == 'x') {
			if (print) printf("일단 삭제: map[%d][%d]\n", h, start);
			map[h][start] = '.';
			if (start + 1 <= C && map[h][start + 1] == 'x') {
				for (int j = 1; j <= R; j++) {
					for (int k = 1; k <= C; k++)
						visited[j][k] = false;
				}
				connected = false;
				while (!del.empty()) del.pop_back();
				dfs(h, start + 1);
				//아래로 내리는 과정
				if (!connected) {
					get_min_dist();
					if (min_dist != INF) go_down();
				}
			}
			if (h - 1 >= 1 && map[h - 1][start] == 'x' && connected) {
				connected = false;
				while (!del.empty()) del.pop_back();
				for (int j = 1; j <= R; j++) {
					for (int k = 1; k <= C; k++)
						visited[j][k] = false;
				}
				dfs(h - 1, start);
				if (!connected) {
					get_min_dist();
					if (min_dist != INF) go_down();
				}
			}
		}
		else if (i % 2 == 1 && map[h][start] == 'x') {
			if (print) printf("일단 삭제: map[%d][%d]\n", h, start);
			map[h][start] = '.';
			if (start - 1 <= C && map[h][start - 1] == 'x') {
				connected = false;
				while (!del.empty()) del.pop_back();
				for (int j = 1; j <= R; j++) {
					for (int k = 1; k <= C; k++)
						visited[j][k] = false;
				}
				dfs(h, start - 1);
				//아래로 내리는 과정
				if (!connected) {
					get_min_dist();
					if (min_dist != INF) go_down();
				}
			}
			if (h - 1 >= 1 && map[h - 1][start] == 'x' && connected) {
				connected = false;
				while (!del.empty()) del.pop_back();
				for (int j = 1; j <= R; j++) {
					for (int k = 1; k <= C; k++)
						visited[j][k] = false;
				}
				dfs(h - 1, start);
				if(!connected){
				get_min_dist();
				if (min_dist != INF) go_down();
				}       
			}
		}
		if (print) print_map();
	}
	print_map();
	return 0;
}

void dfs(int x, int y) {
	if (connected) return;
	if (x == R) {
		connected = true;
		return;
	}
	if (print) printf("dfs(%d, %d)\n", x, y);
	del.push_back(make_pair(x, y));
	visited[x][y] = true;
	int d = x + 1;
	
	//if (print) cout << "dist: " << d-x-1 << " min_dist: " << min_dist << endl;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || nx > R || ny < 1 || ny > C || map[nx][ny] != 'x' || visited[nx][ny]) continue;
		dfs(nx, ny);
	}
}

void go_down() {
	if (print) cout << "go_down --- min_dist: " << min_dist << endl;
	for (int i = 0; i < del.size(); i++) {
		int m_x = del[i].first + min_dist;
		int m_y = del[i].second;
		make.push_back(make_pair(m_x, m_y));
	}
	while (!del.empty()) {
		int del_x = del.back().first;
		int del_y = del.back().second;
		if (print) printf("del_x: %d, del_y: %d\n", del_x, del_y);
		if (print && map[del_x][del_y] != 'x') cout << "/////////////////오류1////////////////" << endl;
		map[del_x][del_y] = '.';
		del.pop_back();
	}
	while (!make.empty()) {
		int make_x = make.back().first;
		int make_y = make.back().second;
		if (print && map[make_x][make_y] != '.') cout << "/////////////////오류2////////////////" << endl;
		map[make_x][make_y] = 'x';
		make.pop_back();
	}
	
}

void print_map() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}

void get_min_dist() {
	min_dist = INF;
	if (print) cout << "get_min_dist()" << endl;
	vector<pair<int, int>> bottom;
	for (int i = 1; i <= C; i++) {
		for (int j = R; j >= 1; j--) {
			if (visited[j][i] && map[j+1][i]) {
				bottom.push_back(make_pair(j, i));
				if (print)cout << "push: " << j << " " << i << endl;
				break;
			}
		}
	}
	while (!bottom.empty()) {
		int now_x = bottom.back().first;
		int now_y = bottom.back().second;
		int save_x = now_x;
		if (print) cout << "save_x: " << save_x << "now_y: " << now_y << endl;
		now_x++;
		while (now_x <= R && map[now_x][now_y] != 'x') now_x++;
		if (print) cout << "now_x: " << now_x << endl;
		min_dist = min(min_dist, now_x - save_x - 1);
		bottom.pop_back();
	}
	if (print) cout << "min_dist: " << min_dist << endl;
}