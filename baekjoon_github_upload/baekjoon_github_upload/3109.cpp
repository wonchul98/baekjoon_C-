#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

using namespace std;

int visitedarr[10005][505];
int dx = 1;
int dy[3] = { -1,0,1 };
queue<int> Q;

bool visited(int a, int b);
void print_arr(int R, int C);

int main(){
	freopen("input.txt", "r", stdin);
	int R, C;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char input;
			cin >> input;
			if (input == 'x') visitedarr[i][j] = 1;
		}
	}
	print_arr(R, C);
	int ans = 0;
	for (int i = 0; i < R; i++) {
		cout << "i: " << i << endl;
		int nx = 0, ny = i;
		bool flag = false;
		while (nx != C - 1) {
			//cout << "nx: " << nx << " ny: " << ny << endl;
			flag = false;
			for (int j = 0; j < 3; j++) { 
				if (!visited(ny + dy[j], nx + dx) && ny + dy[j] > -1 && ny + dy[j] < R) {
					nx += dx;
					ny += dy[j];
					Q.push(ny);
					flag = true;
					printf("%d %d 방문\n", ny, nx);
					break;
				}
			}
			if (!flag) continue; //진행이 안된경우
		}
		if (flag) { //끝까지 진행이 된 경우
			int k = 1;
			while (!Q.empty()) {
				visitedarr[Q.front()][k] = 1;
				Q.pop();
				k++;
			}
			ans++;
			print_arr(R, C);
		}
		else { //중간에 멈춘 경우
			cout << "중간에 멈춰서 Q를 비움!" << endl;
			while (!Q.empty()) {
				Q.pop();
			}
		}
	}
	cout << ans;
	return 0;
}

bool visited(int a, int b) {
	if (visitedarr[a][b] == 1) return true;
	else return false;
}

void print_arr(int R, int C) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << visitedarr[i][j]<<" ";
		}
		cout << endl;
	}
}