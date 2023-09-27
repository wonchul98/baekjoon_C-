#include<iostream>
#include<cmath>
#include<queue>
#include<utility>
using namespace std;
int N, M;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int map[20][20];
int cnt;
int com_b;
int score;
bool visited[20][20];
bool rm_visited[20][20];
int select_group();
void DFS(int x, int y, int color);
void remove_DFS(int x, int y, int color);
void gravity();
void rotate();
void print_map();
queue<pair<int, int>> q2;
bool print =  false;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	long long rst_score = 0;
	int get_score;
	do {
		get_score = select_group();
		if (print)cout << "get_score: " << get_score << endl;
		if (get_score == 0) break;
		rst_score += get_score;
		gravity();
		if (print)print_map();
		rotate();
		if (print)print_map();
		gravity();
		if (print)print_map();
	} while (true);
	cout << rst_score << endl;
	return 0;
}

int select_group() {
	int max_count = 0;
	int max_score = 0;
	int max_rainbow = 0;
	int cur_i, cur_j;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
			rm_visited[i][j] = false;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && map[i][j] != -1 && map[i][j] != 0 && map[i][j] != -2) {
				cnt = 0;
				com_b = 0;
				score = 0;
				DFS(i, j, map[i][j]);
				if (print)printf("DFS(%d, %d) 결과: cnt: %d, com_b: %d, max_rainbow: %d\n", i, j, cnt, com_b, max_rainbow);
				if (cnt >= 2) {
					if (max_count < cnt) {
						max_count = cnt;
						max_score = pow(max_count, 2);
						max_rainbow = cnt - com_b;
						cur_i = i;
						cur_j = j;
					}
					else if (max_count == cnt) {
						if (cnt - com_b >= max_rainbow) {
							max_count = cnt;
							max_score = pow(max_count, 2);
							max_rainbow = cnt - com_b;
							cur_i = i;
							cur_j = j;
						}
					}
				}
				while (!q2.empty()) {
					visited[q2.front().first][q2.front().second] = false;
					if (print) printf("방문처리 해제: (%d, %d)\n", q2.front().first, q2.front().second);
					q2.pop();
				}
			}
			
		}
	}
	if (max_score == 0) return 0;
	remove_DFS(cur_i, cur_j, map[cur_i][cur_j]);
	if (print)print_map();
	return max_score;
}
void DFS(int x, int y, int color) {
	if ((map[x][y] != color && map[x][y] != 0)||map[x][y] == -2) return;
	if (map[x][y] == 0)q2.push(make_pair(x, y));
	//printf("DFS(%d, %d, %d)\n", x, y, color);
	visited[x][y] = true;
	cnt++;
	if (map[x][y] != 0) com_b++;
	//아래 수정
	for (int i = 0; i < 4; i++) {
		int n_x = x + dx[i];
		int n_y = y + dy[i];
		if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N) continue;
		if (!visited[n_x][n_y]) DFS(n_x, n_y, color);
		
	}
	
	return;
}

void remove_DFS(int x, int y, int color) {
	//printf("remove_DFS(%d, %d, %d)\n", x, y, color);
	if (map[x][y] != color && map[x][y] != 0) return;
	rm_visited[x][y] = true;
	map[x][y] = -2;
	for (int i = 0; i < 4; i++) {
		int n_x = x + dx[i];
		int n_y = y + dy[i];
		if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N) continue;
		if (!rm_visited[n_x][n_y]) remove_DFS(n_x, n_y, color);
	}
}

void gravity() {
	for (int i = 0; i < N; i++) { //열 값
		queue<int> q;
		int bottom = N-1;
		int num = 0;
		for (int j = N-1; j >= 0; j--) {//행 값
			if (map[j][i] != -1) { //흑색이 아닌 블록
				if (map[j][i] != -2) { //일반 블록
					q.push(map[j][i]);
				}
				else { //빈 블록
					num++;
				}
			}
			else { // 흑색 블록
				int iter = bottom;
				for (int k = 0; k < num; k++) q.push(-2);
				while (!q.empty()) {
					map[iter--][i] = q.front();
					q.pop();
				}
				bottom = j - 1;
				num = 0;
			}
			if (j == 0) {
				int iter = bottom;
				for (int k = 0; k < num; k++) q.push(-2);
				while (!q.empty()) {
					map[iter--][i] = q.front();
					q.pop();
				}
			}
		}
	}
}

void rotate() {
	int new_map[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			new_map[i][j] = map[j][N - i - 1];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = new_map[i][j];
		}
	}
}

void print_map() {
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout.width(3);
			cout << map[i][j];
		}
		cout << "\n";
	}
	cout << "//////////////" << endl;
}
