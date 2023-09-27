#include<iostream>
#include<vector>
using namespace std;
int N, M;
int map[200][200];
bool visited[200];
vector<int> lines[200];
void DFS(int node);
bool print = false;
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;
			if (input == 1) lines[i].push_back(j);
			map[i][j] = input;
		}
	}
	
	for (int i = 0; i < N; i++) visited[i] = false;
	int first;
	cin >> first;
	visited[first-1] = true;
	DFS(first-1);
	
	bool flag = true;
	for (int i = 1; i < M; i++) {
		int input;
		cin >> input;
		if (!visited[input-1]) {
			flag = false;
			break;
		}
	}
	
	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}

void DFS(int node) {
	if (print)printf("DFS(%d)\n", node);
	visited[node] = true;
	for (int i = 0; i < lines[node].size(); i++) {
		int next = lines[node][i];
		if (!visited[next] && map[node][next]) DFS(next);
	}
}