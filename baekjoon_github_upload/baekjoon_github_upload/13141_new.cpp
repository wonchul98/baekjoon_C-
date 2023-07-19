#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define ll long long
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool print = false;
int N, M;
int dist[201][201];
struct INFO {
	int S, E, L;
};
vector<INFO> lines(20000);
void print_dist() {
	if (print) {
		cout << "dist배열 " << endl;
		for (int s = 1; s <= N; s++) {
			for (int e = 1; e <= N; e++) {
				if (dist[s][e] == INF) cout << "X ";
				else cout << dist[s][e] << " ";
			}
			cout << "\n";
		}
	}
}



int main() {
	freopen("input/13141_input.txt", "r", stdin);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int start, end, length;
		cin >> start >> end >> length;
		lines[i].S = start;
		lines[i].E = end;
		lines[i].L = length;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF; //간선이 없는 경우
		}
	}
	for (int i = 0; i < M; i++) {
		dist[lines[i].S][lines[i].E] = min(dist[lines[i].S][lines[i].E], lines[i].L);
		dist[lines[i].E][lines[i].S] = min(dist[lines[i].S][lines[i].E], lines[i].L);
	}
	print_dist();
	for (int m = 1; m <= N; m++) {
		for (int s = 1; s <= N; s++) {
			for (int e = 1; e <= N; e++) {
				dist[s][e] = min(dist[s][e], dist[s][m] + dist[m][e]); //floyd warshall
			}
		}
	}
	print_dist();
	ll ans = INF;
	for (int s = 1; s <= N; s++) {
		ll max_len = 0;
		if (print) cout << "starting point: " << s << endl;
		for (int i = 0; i < M; i++) {
			int one = lines[i].S;
			int two = lines[i].E;
			ll len = (dist[s][one] + dist[s][two] + lines[i].L);
			max_len = max(max_len, len);
			if (print) printf("one: %d, two: %d, len: %2f, max_len: %2f\n", one, two, len, max_len);
		}
		if (print) cout << s << " 에서 시작하는 최대 시간: " << max_len << endl;
		ans = min(ans, max_len);
		if (print) cout << "현재ans: " << ans << endl;
	}
	cout << fixed;
	cout.precision(1);
	cout << ans / 2 << "." << (ans%2) * 5;
	return 0;
}