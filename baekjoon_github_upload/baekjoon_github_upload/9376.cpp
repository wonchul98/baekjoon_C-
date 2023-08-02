#define _CRT_SECURE_NO_WARNINGS
#define INF 2100000000
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

char map[102][102];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int sx1, sy1, sx2, sy2;
int TC, h, w;
int min_cost;
bool print = false;

int dij[3][102][102];
bool visited[3][102][102];

void setting();
void solution();
void dijkstra(int x, int y, int p);
void cal_cost();
struct VertexInfo {
	int x;
	int y;
	int cost;

	bool operator <(const VertexInfo& v) const{
		return cost > v.cost;
	}
};


int main() {
	//freopen("input/9376_input.txt", "r", stdin);
	
	cin >> TC;
	while (TC--) {
		setting();
		solution();
	}
	return 0;
}

void setting() {
	/* 초기화 */
	sx1 = -1; sx2 = -1; sy1 = -1; sy2 = -1;
	min_cost = 987654321;
	cin >> h >> w;
	if (print) printf("h: %d, w: %d\n", h, w);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= h + 1; j++) {
			for (int k = 0; k <= w + 1; k++) {
				dij[i][j][k] = INF;
				visited[i][j][k] = false;
			}
		}
	}
	for (int i = 0; i <= h + 1; i++) {
		for (int j = 0; j <= w + 1; j++) {
			
			if (i == 0 || i == h + 1 || j == 0 || j == w + 1) {
				map[i][j] = '.';
			}
			else {
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
	if (print) {
		for (int i = 0; i <= h + 1; i++) {
			for (int j = 0; j <= w + 1; j++) {
				cout << map[i][j];
			}
			cout << endl;
		}
	}
	
}

void solution() {
	dijkstra(0, 0, 0);
	dijkstra(sx1, sy1, 1);
	dijkstra(sx2, sy2, 2);
	cal_cost();
	cout << min_cost << endl;
}

void dijkstra(int x, int y, int p) {
	if (print)printf("dijkstra(%d, %d, %d)\n", x, y, p);
	priority_queue<VertexInfo> pq; //오름차순으로 해야함
	visited[p][x][y] = true;
	pq.push({ x, y, 0 });
	while (!pq.empty()) {
		int cur_x = pq.top().x;
		int cur_y = pq.top().y;
		int cur_c = pq.top().cost;
		pq.pop();
		if (print)printf("cur_x: %d, cur_y: %d, cur_c: %d\n", cur_x, cur_y, cur_c);
		if (dij[p][cur_x][cur_y] <= cur_c) continue;
		dij[p][cur_x][cur_y] = cur_c;
		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (nx < 0 || nx > h + 1 || ny < 0 || ny > w + 1) continue;
			else {
				if (!visited[p][nx][ny]) { //처음 방문하는 곳 인 경우
					if (map[nx][ny] == '.') {
						if (print)printf("pushed: %d, %d, %d\n", nx, ny, cur_c);
						pq.push({ nx, ny, cur_c });
						visited[p][nx][ny] = true;
					}
					else if (map[nx][ny] == '#') {
						if (print)printf("pushed: %d, %d, %d\n", nx, ny, cur_c + 1);
						pq.push({ nx, ny, cur_c + 1});
						visited[p][nx][ny] = true;
					}
				}
				else { //이미 방문한 적 있는 경우
					if (map[nx][ny] == '.' && dij[p][nx][ny] > cur_c) {
						if (print)printf("(재방문)pushed: %d, %d, %d\n", nx, ny, cur_c);
						pq.push({ nx, ny, cur_c });
					}
					else if (map[nx][ny] == '#' && dij[p][nx][ny] > cur_c + 1) {
						if (print)printf("(재방문)pushed: %d, %d, %d\n", nx, ny, cur_c + 1);
						pq.push({ nx, ny, cur_c + 1 });
					}
				}
			}
		}
	}
	if (print) {
		for (int i = 0; i <= h + 1; i++) {
			for (int j = 0; j <= w + 1; j++) {
				if (dij[p][i][j] == INF) cout << "x";
				else cout << dij[p][i][j];
			}
			cout << endl;
		}
	}	
}
void cal_cost() {
	if (print) cout << "cal_cost" << endl;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			int c = 0;
			for (int k = 0; k < 3; k++) {
				if (dij[k][i][j] != INF) c += dij[k][i][j]; //오버플로우 조심
				else c = INF;
			}
			if (map[i][j] == '#') c -= 2;
			min_cost = min(min_cost, c);
			if (print) {
				if (c >= INF) cout << "x";
				else cout << c;
			}
		}
		if(print) cout << endl;
	}
}