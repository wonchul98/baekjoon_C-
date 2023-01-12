#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

queue<pair<int, int>> curWaterQ;
queue<pair<int, int>> nextWaterQ;
queue<pair<int, int>> curSwanQ;
queue<pair<int, int>> nextSwanQ;

int flag = 0;
int visited_arr[1501][1501];
bool visited(int a, int b);
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue<pair<int, int>> waterBFS(int R, int C, char l_array[1502][1502], queue<pair<int, int>> curWaterQ);
queue<pair<int, int>> swanBFS(int R, int C,char l_array[1502][1502], queue<pair<int, int>> curSwanQ);
void print_arr(int R, int C, char l_array[1502][1502]);

int main() {
	int R, C, lx, ly;
	cin >> R >> C;
	char l_array[1502][1502];
	for (int i = 1; i <= R; i++) {
		string input;
		cin >> input;
		for (int j = 1; j <= C; j++) {
			l_array[i][j] = input[j - 1];
			if (input[j - 1] == '.') curWaterQ.push(make_pair(i, j));
			if (input[j - 1] == 'L') {
				curWaterQ.push(make_pair(i, j));
				lx = i;
				ly = j;
			}

		}
	}
	curSwanQ.push(make_pair(lx, ly));
	//visited_arr[lx][ly] = 1;
	int cnt = 0;

	while (!flag) {
		//cout << "//////////////////////\n";
		cnt++;
		//cout << "cnt: " << cnt << endl;
		nextWaterQ = waterBFS(R, C, l_array, curWaterQ);
		curWaterQ = nextWaterQ;
		//print_arr(R, C, l_array);
		//cout << "swanBFS\n";
		nextSwanQ = swanBFS(R, C, l_array, curSwanQ);
		curSwanQ = nextSwanQ;

		while (!nextWaterQ.empty()) {
			l_array[nextWaterQ.front().first][nextWaterQ.front().second] = '.';
			nextWaterQ.pop();
		}

		
		//print_arr(R, C, l_array);
		
	}
	
	cout << --cnt;
	return 0;
}

bool visited(int a, int b) {
	if (visited_arr[a][b] == 1) return true;
	return false;
}

queue<pair<int, int>> waterBFS(int R, int C, char l_array[1502][1502], queue<pair<int, int>> curWaterQ) {
	queue<pair<int, int>> nextWaterQ;
	while (!curWaterQ.empty()) {
		//cout << "while in waterBFS" << endl;
		for (int i = 0; i < 4; i++) {
			int newX = curWaterQ.front().first + dx[i];
			int newY = curWaterQ.front().second + dy[i];
			if ((newX > 0 || newX <= R) && newY > 0 || newY <= C) {
				if (l_array[newX][newY] == 'X') {
					nextWaterQ.push(make_pair(newX, newY));
					//l_array[newX][newY] = 'x';
				}
			}
		}
		curWaterQ.pop();
	}
	return nextWaterQ;
}

queue<pair<int, int>> swanBFS(int R, int C, char l_array[1502][1502], queue<pair<int, int>> curSwanQ) {
	queue<pair<int, int>> nextSwanQ;
	while (!curSwanQ.empty()) {
		if (visited(curSwanQ.front().first, curSwanQ.front().second)) {
			curSwanQ.pop();
			continue;
		}
		//cout << "while in SwanBFS:" << curSwanQ.front().first << " " << curSwanQ.front().second << endl;
		visited_arr[curSwanQ.front().first][curSwanQ.front().second] = 1;
		
		for (int i = 0; i < 4; i++) {
			int newX = curSwanQ.front().first + dx[i];
			int newY = curSwanQ.front().second + dy[i];
			if (visited(newX, newY)) continue;
			else if ((newX > 0 || newX <= R) && newY > 0 || newY <= C) {
				if (l_array[newX][newY] == 'X') {
					nextSwanQ.push(make_pair(newX, newY));
					//cout << "1: " << newX << newY << endl;
				}
				if (l_array[newX][newY] == '.') {
					curSwanQ.push(make_pair(newX, newY));
					//cout << "2: " << newX << newY << endl;
				}
				if (l_array[newX][newY] == 'L') {
					flag = 1;
					//cout << "found" << endl;
				}
			}
		}
		curSwanQ.pop();
	}
	return nextSwanQ;
}

void print_arr(int R, int C, char l_array[1502][1502]) {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << l_array[i][j];
		}
		cout << "\n";
	}
}