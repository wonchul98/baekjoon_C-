#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
int N, M, D;
int shooter[3];
int map[15][15] = { 0, };
int new_map[15][15];

int shoot();
void renew_map();
void print_map();
int main() {
	int ans = 0;
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i <= M - 3; i++) {
		for (int j = i + 1; j <= M - 2; j++) {
			for (int k = j + 1; k <= M - 1; k++) {
				int count = 0;
				/*얕은 복사*/
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						new_map[i][j] = map[i][j];
					}
				}
				//cout << i << " " << j << " " << k << endl;
				for (int l = 0; l < N; l++) {
					shooter[0] = i;
					shooter[1] = j;
					shooter[2] = k;
					count += shoot();
					renew_map();
				}
				//cout << "count: " << count << endl;
				ans = max(ans, count);
			}
		}
	}
	cout << ans << endl;
	return 0;
}

int shoot() {
	
	int cnt = 0;
	bool visited[15][15] = {false, };
	queue<pair<int, int>> q;
	/* 우선순위 대로 scan하는 알고리즘 */
	for (int i = 0; i < 3; i++) {
		bool flag = false;
		int now_s = shooter[i]; //현재 궁수
		for (int distance = 1; distance <= D; distance++) {
			for (int idx = -1 * (distance - 1); idx <= distance - 1; idx++) {
				int x = N + abs(idx) - distance;
				int y = now_s + idx;
				/* 유효성 검증 */
				if (x < 0 || x >= N || y < 0 || y >= M) continue;
				if (new_map[x][y] == 1) {
					//printf("q에 (%d, %d) push\n", x, y);
					q.push(make_pair(x, y));
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
	}
	while (!q.empty()) {
		new_map[q.front().first][q.front().second] = 0;
		if (!visited[q.front().first][q.front().second]) {
			visited[q.front().first][q.front().second] = true;
			cnt++;
		}
		q.pop();
	}
	return cnt;
}

void renew_map() {
	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			new_map[i + 1][j] = new_map[i][j];
		}
	}
	for (int i = 0; i < M; i++) new_map[0][i] = 0;
	//print_map();
}

void print_map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout.width(3);
			cout << new_map[i][j];
		}
		cout << "\n";
	}
	cout << "//////////////////////" << endl;
}