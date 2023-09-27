#include<iostream>
#include<cmath>
#include<queue>
#include<utility>
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = {0, 0, -1, 1};
int map[66][66] = { 0, };
int num;
bool visited[66][66];
int N, Q, msize;
void rotate(int command);
void del();
void print_map();
int ice_add();
int biggest();
void DFS(int x, int y);
bool print = false;
int main() {
	cin >> N >> Q;
	msize = pow(2, N);
	for (int i = 0; i <= msize+1; i++) {
		for (int j = 0; j <= msize+1; j++) {
			visited[i][j] = false;
		}
	}
	for (int i = 1; i <= msize; i++) {
		for (int j = 1; j <= msize; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < Q; i++) {
		int L;
		cin >> L;
		rotate(L);
		if(print) print_map();
		del();
		if (print) print_map();
	}
	cout << ice_add() << endl;
	cout << biggest() << endl;
	return 0;
}
void rotate(int L) {
	int L2 = pow(2, L);
	int for_size = msize / L2;
	int new_map[66][66] = { 0, };
	for (int i = 0; i < for_size; i++) {
		for (int j = 0; j < for_size; j++) {
			for (int k = 0; k < L2; k++) {
				for (int l = 0; l < L2; l++) {
					new_map[L2 * i + k + 1][L2 * j + l + 1] = map[L2 * i + L2 - l][L2 * j + k + 1];
				}
			}
		}
	}
	for (int i = 1; i <= msize; i++) {
		for (int j = 1; j <= msize; j++) {
			map[i][j] = new_map[i][j];
		}
	}
}
void del() {
	queue<pair<int, int>> q;
	for (int i = 1; i <= msize; i++) {
		for (int j = 1; j <= msize; j++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int n_x = i + dx[k];
				int n_y = j + dy[k];
				if (map[n_x][n_y] == 0) cnt++;
			}
			if (cnt >= 2 && map[i][j] > 0) {
				q.push(make_pair(i, j));
				if (print) printf("얼음 제거: (%d, %d)\n", i, j);
			}
		}
	}
	while (!q.empty()) {
		map[q.front().first][q.front().second]--;
		q.pop();
	}
}

void print_map() {
	for (int i = 1; i <= msize; i++) {
		for (int j = 1; j <= msize; j++) {
			cout.width(3);
			cout << map[i][j];
		}
		cout << "\n";
	}
}

int ice_add() {
	
	int cnt = 0;
	for(int i = 1; i <= msize;i++) {
		for (int j = 1; j <= msize; j++) {
			cnt += map[i][j];
		}
	}
	return cnt;
}

int biggest() {
	int maximum = 0;
	for (int i = 1; i <= msize; i++) {
		for (int j = 1; j <= msize; j++) {
			if (!visited[i][j] && map[i][j] != 0) {
				num = 0;
				DFS(i, j);
				maximum = max(maximum, num);
			}
		}
	}
	return maximum;
}

void DFS(int x, int y) {
	//printf("DFS(%d, %d)\n", x, y);
	visited[x][y] = true;
	num++;
	for (int i = 0; i < 4; i++) {
		int n_x = x + dx[i];
		int n_y = y + dy[i];
		if (n_x < 1 || n_x > msize || n_y < 1 || n_y > msize || visited[n_x][n_y] || map[n_x][n_y]==0) continue;
		DFS(n_x, n_y);
	}
	return;
}