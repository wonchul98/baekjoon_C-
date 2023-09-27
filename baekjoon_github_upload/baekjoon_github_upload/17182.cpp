#define INF 987654321;
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct INFO {
	int x, cost;
};
int N, K;
queue<INFO> v[10];
int map[10][10];
void DFS(int start, int cost);
int min_cost = INF;
bool visited[10];
bool print = false;
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;
			map[i][j] = input;
		}
	}
	//floyd warshall
	for (int mid = 0; mid < N; mid++) {
		for (int start = 0; start < N; start++) {
			for (int end = 0; end < N; end++) {
				if (map[start][mid] == 0 || map[mid][end] == 0) continue;
				map[start][end] = min(map[start][end], map[start][mid] + map[mid][end]);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			INFO put;
			put.x = j;
			put.cost = map[i][j];
			if (map[i][j] != 0) v[i].push(put);
		}
	}
	for (int i = 0; i < N; i++) visited[i] = false;
	visited[K] = true;
	DFS(K, 0);
	cout << min_cost << endl;
	return 0;
}

void DFS(int start, int cost) {
	bool flag = false;;
	for (int i = 0; i < N; i++) {
		if (!visited[i]) { //아직 안간 곳이 있다면
			flag = true;
			break;
		}
	}
	if (!flag) {
		min_cost = min(min_cost, cost);
		return;
	}
	if (print) printf("DFS(%d, %d)\n",start, cost);
	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		int next = i;
		int next_cost = cost + map[start][next];
		if (next_cost > min_cost) continue;
		visited[next] = true;
		DFS(next, next_cost);
		visited[next] = false;
	}
}