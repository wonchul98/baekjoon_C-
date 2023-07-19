#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool print = true;
int N, M;
int lines[201][201];
int dist[201][201];
vector<pair<int, int>> gen_lines;

int main() {
	freopen("input/13141_input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int start, end, length;
		cin >> start >> end >> length;
		gen_lines.push_back(make_pair(start, end));
		lines[start][end] = min(length, lines[start][end]);
		lines[end][start] = min(length, lines[end][start]);
		
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) dist[i][j] = 0;
			else if(lines[i][j]) dist[i][j] = lines[i][j];
			else dist[i][j] = INF; //간선이 없는 경우
		}
	}
	if (print) {
		cout << "dist배열 " << endl;
		for (int s = 1; s <= N; s++) {
			for (int e = 1; e <= N; e++) {
				if (dist[s][e] == 987654321) cout << "X ";
				else cout << dist[s][e] << " ";
			}
			cout << "\n";
		}
	}
	for (int m = 1; m <= N; m++) {
		for (int s = 1; s <= N; s++) {
			for (int e = 1; e <= N; e++) {
				dist[s][e] = min(dist[s][e], dist[s][m] + dist[m][e]); //floyd warshall
			}
		}
	}
	if (print) {
		for (int s = 1; s <= N; s++) {
			for (int e = 1; e <= N; e++) {
				if (dist[s][e] == 987654321) cout << "X" << endl;
				else cout << dist[s][e] << " ";
			}
			cout << "\n";
		}
	}
	float ans = INF;
	for (int s = 1; s <= N; s++) {
		float max_len = 0;
		for (int i = 0; i < M; i++) {
			int one = gen_lines[i].first;
			int two = gen_lines[i].second;
			float near, far;
			if (dist[s][one] > dist[s][two]) {
				near = dist[s][two];
				far = dist[s][one];
			}
			else {
				near = dist[s][one];
				far = dist[s][two];
			}
			float len = (far + near + lines[one][two]) / 2;
			max_len = max(max_len, len);
			if(print) printf("one: %d, two: %d, near: %2f, far: %2f, len: %2f, max_len: %2f\n", one, two, near, far, len, max_len);

		}
		if (print) cout << s << " 에서 시작하는 최대 시간: " << max_len << endl;
		ans = min(ans, max_len);
		if (print) cout << "현재ans: " << ans << endl;
	}
	cout << fixed;
	cout.precision(1);
	cout << ans << endl;
	return 0;
}