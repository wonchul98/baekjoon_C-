#include<iostream>
#include<queue>

using namespace std;
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

char garray[10][10];
int visitedarr[10][10][10][10] = {0,};
int flag = 0;
int bluecol;
int bluerow;
int redcol;
int redrow;
int CNT = 1;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> Q;

void printarray(char array[10][10], int N, int M);
void BSF();
bool visited(int a, int b, int c, int d);

int main() {
	int N, M;
	char input;
	cin >> N >> M; //3 <= n,m <= 10
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input;
			garray[i][j] = input;
			if (input == 'B') {
				bluerow = i;
				bluecol = j;
				garray[i][j] = '.';
			}
			else if (input == 'R') {
				redrow = i;
				redcol = j;
				garray[i][j] = '.';
				visitedarr[redrow][redcol][bluerow][bluecol] = 1;
			}
		}
	}
	//printarray(garray, N, M);
	BSF();
	printf("%d\n", CNT);
}

void printarray(char array[10][10], int N, int M) {
	printf("=======print array======\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	printf("=======================\n");
}

void BSF() {
	int i = 0;
	int nextlim = 1;
	int cur_cnt = 1, next_cnt = 0;
	bool redflag = false;
	bool blueflag = false;
	bool pushflag = false;
	Q.push(make_pair(redrow, redcol));
	Q.push(make_pair(bluerow, bluecol));
	visitedarr[redrow][redcol][bluerow][bluecol] = 1;
	while (!Q.empty() && CNT <= 10 && !redflag) {
		bool moved = false;
		//printf("CNT: %d\n", CNT);
		redrow = Q.front().first;
		redcol = Q.front().second;
		int saveredcol = redcol; int saveredrow = redrow; 
		//printf("빨간 공 위치:%d %d\n", redrow, redcol);
		Q.pop();
		bluerow = Q.front().first;
		bluecol = Q.front().second;
		int savebluerow = bluerow; int savebluecol = bluecol;
		//cout << "파란 공 위치:" << bluerow << " " << bluecol << endl;
		//cout << redrow << " " << redcol << " " << bluerow << " " << bluecol << endl;
		Q.pop();
		cur_cnt--;
		for (int i = 0; i < 4; i++) {
			pushflag = false;
			int redmove = 0;
			int bluemove = 0;
			//if (visited(redrow + dx[i], redcol + dy[i], bluerow, bluecol)) continue;
			if (garray[redrow + dx[i]][redcol + dy[i]] != '#') {
				while (garray[redrow + dx[i]][redcol + dy[i]] != '#') {
					pushflag = true;
					redmove++;
					redrow += dx[i]; //진행
					redcol += dy[i]; //진행
					//cout << "red: " << redrow << " " << redcol << endl;
					if (garray[redrow][redcol] == 'O') {
						//cout << "redflag" << endl;
						redflag = true;
						break;
					}

				}
			}
			
			while (garray[bluerow + dx[i]][bluecol + dy[i]] != '#') {
				pushflag = true;
				bluemove++;
				bluerow += dx[i];
				bluecol += dy[i];
				//cout << "blue: "<<bluerow << " "<<bluecol << endl;
				if (garray[bluerow][bluecol] == 'O') {
					//cout << "blueflag" << endl;
					blueflag = 1;
					break;
				}
			}
			if (redflag && !blueflag) { 
				//cout << "redflag break" << endl;
				break; 
			}
			if (blueflag) {
				//cout << "같이 들어옴 -> continue" << endl;
				//cout << "blueflag: " << blueflag << "redflag: "<<redflag<<endl;
				redflag = false;
				blueflag = false;
				redcol = saveredcol;
				redrow = saveredrow;
				bluerow = savebluerow;
				bluecol = savebluecol;
				continue;
			}
			if (redrow == bluerow && redcol == bluecol) {
				if (redmove > bluemove) {
					redrow -= dx[i];
					redcol -= dy[i];
				}
				else {
					bluerow -= dx[i];
					bluecol -= dy[i];
				}
			}
			if (pushflag) {
				if (!visited(redrow, redcol, bluerow, bluecol)) {
					//cout << "pushed(" << redrow << "," << redcol << ")" << "(" << bluerow << "," << bluecol << ")" << endl;
					visitedarr[redrow][redcol][bluerow][bluecol] = 1;
					Q.push(make_pair(redrow, redcol));
					Q.push(make_pair(bluerow, bluecol));
					next_cnt++;
				}
				
			}
			redcol = saveredcol;
			redrow = saveredrow;
			bluecol = savebluecol;
			bluerow = savebluerow;
		}
		//cout << "cur_cnt: " << cur_cnt << " next_cnt: " << next_cnt << endl;
		if (cur_cnt == 0&&!redflag) {
			//cout << "CNT++" << endl;
			CNT++;
			cur_cnt = next_cnt;
			next_cnt = 0;
		}

	}
	if (!redflag) CNT = -1;
}

bool visited(int a, int b, int c, int d) {
	if (visitedarr[a][b][c][d] == 1) return true;
	else return false;
}