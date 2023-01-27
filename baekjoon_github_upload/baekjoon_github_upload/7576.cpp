#include<iostream>
#include<queue>

using namespace std;

int M, N;
int visitedarr[1000][1000]={0,};
int cur_cnt=0, next_cnt=0, cnt=0;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int map[1000][1000] = {0,};
queue<pair<int,int>> Q;

void bsf();
bool visited(int a, int b);
void printarr();
int main() {
	cin >> M >> N;
	int input;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input;
			map[i][j] = input;
			if (input == 1) {
				Q.push(make_pair(i, j)); 
				cur_cnt++;
			}
			
		}
	}
	bsf();
	cout << cnt << endl;
}

void bsf() {
	int nx, ny;
	while (!Q.empty()) {
		//cout << "cur_cnt: " << cur_cnt << "next_cnt: "<<next_cnt<<endl;
		nx = Q.front().first;
		ny = Q.front().second;
		Q.pop();
		map[nx][ny] = 1;
		//cout << nx << " " << ny << endl;
		cur_cnt--;
		visitedarr[nx][ny] = 1;
		for (int i = 0; i < 4; i++) {
			if (nx + dx[i] >= 0 && nx + dx[i] < N && ny + dy[i] >= 0 && ny + dy[i] < M) {
				if (map[nx + dx[i]][ny + dy[i]] == 0 && !visited(nx + dx[i], ny + dy[i])) {
					Q.push(make_pair(nx + dx[i], ny + dy[i]));
					visitedarr[nx + dx[i]][ny + dy[i]] = 1;
					next_cnt++;
					//cout << "pushed(" << nx + dx[i] << "," << ny + dy[i] << ")" << endl;
				}
			}
		}
		if (cur_cnt == 0&&!Q.empty()) {
			//printarr();
			//cout << "cnt++" << endl;
			cnt++;
			cur_cnt = next_cnt;
			next_cnt = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) cnt = -1;
		}
	}
}

bool visited(int a, int b) {
	if (visitedarr[a][b] == 1) return true;
	else return false;
}

void printarr() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << visitedarr[i][j] << " ";
		}
		cout << endl;
	}
}
