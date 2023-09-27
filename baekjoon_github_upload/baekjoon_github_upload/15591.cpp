#define ll long long
#define INF 987654321987654321
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct INFO {
	int to;
	ll dist;
};
int N, Q;
vector<INFO> v[5001];
bool visited[5001][5001];
ll min_dist[5001][5001];
bool print = false;
int main() {
	cin >> N >> Q;
	for (int i = 1; i < N; i++) {
		int from1, to1;
		ll cost;
		cin >> from1 >> to1 >> cost;
		INFO input;
		input.to = to1;
		input.dist = cost;
		v[from1].push_back(input);
		input.to = from1;
		v[to1].push_back(input);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			min_dist[i][j] = INF;
		}
	}
	while (Q--) {

		int ans = 0;
		int K, start;
		cin >> K >> start;
		for (int i = 1; i <= N; i++)visited[start][i] = false;
		queue<int> q;
		q.push(start);
		while (!q.empty()) {
			int mid = q.front();
			visited[start][mid] = true;

			q.pop();
			for (int i = 0; i < v[mid].size(); i++) {
				int end = v[mid][i].to;
				ll dist = v[mid][i].dist;
				if (visited[start][end] || dist < K) continue;
				q.push(end);
				min_dist[start][end] = min(min_dist[start][mid], dist);
				visited[start][end] = true;
				if (min_dist[start][end] >= K) ans++;
				if (print) printf("min_dist[%d][%d]: %d\n", start, end, min_dist[start][end]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
