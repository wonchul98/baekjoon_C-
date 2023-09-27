#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int visited[1501][1501];
int flag = 0;
int dx[4] = { -1,1,0 ,0 };
int dy[4] = { 0,0,-1,1 };

void BFS(int R,int C,char l_array[1501][1501], int cur_x, int cur_y, int lx, int ly);
void print_arr(int R, int C, char l_array[1501][1501]);

queue<pair<int, int>> Q;
queue<pair<int, int>> ICE;

int main() {
	int cnt = 0;
	vector<pair<int,int>> W;
	int lx, ly;
	char l_array[1501][1501];
	int R, C;
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		string input;
		cin >> input;
		for (int j = 1; j <= C; j++) {
			l_array[i][j] = input[j - 1];
			if (input[j - 1] == 'L') {
				lx = i;
				ly = j;
			}
			if (input[j - 1] == '.') {
				W.push_back(make_pair(i, j));
			}
		}
	}
	Q.push(make_pair(lx, ly));
	BFS(R, C, l_array, lx, ly, lx, ly);
	while (!Q.empty() || !flag) {
		
		print_arr(R, C, l_array);
		cnt++;
		while (!ICE.empty()) {
			l_array[ICE.front().first][ICE.front().second] = '.';
			Q.push(make_pair(ICE.front().first, ICE.front().second));
			ICE.pop();
			
		}
		cout << "/////////////////////////\n";
	}
	cout << cnt;
}

void BFS(int R, int C, char l_array[1501][1501], int cur_x, int cur_y, int lx, int ly) {
	cout << "BFS of i: " << cur_x << "j: " << cur_y << endl;
	if (visited[cur_x][cur_y] == 1 && (cur_x!= lx || cur_y != ly)) return;
	cout << "111111\n";
	visited[cur_x][cur_y] = 1;
	if (cur_x == lx && cur_y == ly) {
		for (int i = 0; i < 4; i++) {
			if ((cur_x + dx[i] > 0 || cur_x + dx[i] <= R) && (cur_y + dy[i] > 0 || cur_y + dy[i] <= C)) {
				Q.push(make_pair(cur_x + dy[i], cur_y + dy[i]));
			}
		}
	}
	if (l_array[cur_x][cur_y] == 'L' && (cur_x != lx || cur_y != ly)) {
		cout << "L";
		flag = 1;
		return;
	}
	if (l_array[cur_x][cur_y] == 'X') {
		cout << "X";
		ICE.push(make_pair(cur_x, cur_y));
		return;
	}
	if (l_array[cur_x][cur_y] == '.') {
		cout << ".";
		for (int i = 0; i < 4; i++) {
			if ((cur_x + dx[i] > 0 || cur_x + dx[i] <= R) && (cur_y + dy[i] > 0 || cur_y + dy[i] <= C)) {
				Q.push(make_pair(cur_x + dy[i], cur_y + dy[i]));
			}
		}
	}
	
}

void print_arr(int R, int C, char l_array[1501][1501]) {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << l_array[i][j];
		}
		cout << endl;
	}
}