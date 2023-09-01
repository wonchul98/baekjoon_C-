#include<iostream>
#include<vector>
#include<utility>
#include<stack>
using namespace std;
void insider(int x, int y);
char map[102][102];
bool visited[102][102];
vector<pair<int, int>> cheeze;
int N, M;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0,0,1,-1 };


int main() {
	
	cin >> N >> M;
	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			map[i][j] = 'N';
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == '1') {
				cheeze.push_back(make_pair(i, j)); // 치즈에 해당하는 좌표 삽입
				//cout << "치즈 좌표: " << i << " " << j << endl;
			}

		}
	}
	int round = 0;
	while (!cheeze.empty()) {
		//cout << "round: " << round << endl;
		round++;
		insider(0,0); //치즈 안에 있는 공기 구분
		stack<int> bad;
		/*for (int i = 0; i <= N + 1; i++) {
			for (int j = 0; j <= M + 1; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}*/
		//cout << "부식 on" << endl;

		for (int i = 0; i < cheeze.size(); i++) {

			//cout << "i:" << i << endl;
			//cout << cheeze[i].first << " " << cheeze[i].second << endl;
			int cnt=0;
			for (int j = 0; j < 4; j++) {
				if (map[cheeze[i].first + dx[j]][cheeze[i].second + dy[j]] == 'X') cnt++;
			}

			if (cnt >= 2) {
				bad.push(i);
				//printf("(%d, %d) 삭제~\n", cheeze[i].first, cheeze[i].second);
				map[cheeze[i].first][cheeze[i].second] = '0'; //숫자 0
			}
		}
		while (!bad.empty()) {
			cheeze.erase(cheeze.begin() + bad.top());
			bad.pop();
		}
		/*for (int i = 0; i <= N+1; i++) {
			for (int j = 0; j <= M+1; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}*/
		//visited 초기화
		for (int i = 0; i <= N+1; i++) {
			for (int j = 0; j <= M+1; j++) {
				visited[i][j] = false;
			}
		}
	}
	cout << round << endl;
	return 0;
}

void insider(int x, int y) {
	// printf("insider(%d, %d)\n", x, y);
	visited[x][y] = true;
	map[x][y] = 'X'; //문자 X
	/*for (int i = 0; i <= N+1; i++) {
		for (int j = 0; j <= M+1; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}*/
	for (int i = 0; i < 4; i++) {
		
		int n_x = x + dx[i];
		int n_y = y + dy[i];
		if (n_x <0 || n_x > N + 1 || n_y < 0 || n_y > M + 1) continue;
		if (!visited[n_x][n_y] && map[n_x][n_y] != '1') {
			insider(n_x, n_y);
		}
		
	}
	return;
}