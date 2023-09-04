#define _CRT_SECURE_NO_WARNINGS
#define ll long long
#define INF 987654321987654321
#include<iostream>
#include<utility>
#include<queue>
using namespace std;

struct INFO {
	int a, b;
	ll cost;
};
int N, Q;
bool print = true;
ll map[5001][5001];
ll min_dist[5001][5001];
bool n_visited[5001];
void dijkstra(int start, int K);
queue<int> near(int a);
int main() {
	freopen("input/15591_input.txt", "r", stdin);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) { //출발지 = 목적지 이면 유사도 0 (편의상)
				map[i][j] = 0;
				min_dist[i][j] = 0;
			}
			else { //나머지 유사도 INF (편의상) min을 기준으로 선택하기에 usado가 없으면 usado가 있는 경우를 선택하려고  
				map[i][j] = INF;
				min_dist[i][j] = INF;
			}
		}
	}
	for (int i = 1; i < N; i++) {
		int left, right;
		ll dist;
		cin >> left >> right >> dist;
		map[left][right] = dist;
		map[right][left] = dist;
		min_dist[left][right] = dist;
		min_dist[right][left] = dist;
	}
	for (int i = 1; i <= Q; i++) {
		int start, K;
		cin >> K >> start;
		if (print) cout << start << K << endl;
		dijkstra(start, K);
	}
	return 0;
}

void dijkstra(int start, int K) {
	if (print) printf("dijkstra(%d, %d)\n", start, K);
	int ans = 0;
	for (int i = 1; i <= N; i++) n_visited[i] = false;
	queue<int> s_near = near(start); //시작점과 연결되어 있는 점
	while (!s_near.empty()) {
		int mid = s_near.front();
		if (print) cout << "mid: " << mid << endl;
		queue<int> s_end = near(mid);

		while (!s_end.empty()) {
			int end = s_end.front();
			s_near.push(end);
			if (print) cout << "s_near push: " << end << endl;
			min_dist[start][end] = min(min_dist[start][mid], min_dist[mid][end]);
			s_end.pop();
		}
		s_near.pop();
	}
	for (int i = 1; i <= N; i++) {
		if (print) printf("min_dist[%d][%d]: %d\n", start, i, min_dist[start][i]);
		if (min_dist[start][i] >= K) ans++;
	}
	cout << ans << endl;
}

queue<int> near(int a) {
	if (print) printf("near(%d)\n", a);
	n_visited[a] = true;
	if (print) cout << "mid visited: " << a << endl;
	queue<int> ret;
	for (int i = 1; i <= N; i++) {
		if (min_dist[a][i] != INF && !n_visited[i]) {
			ret.push(i);
			if(print) cout << "pushed:" << i << endl;
		}
	}
	return ret;
}