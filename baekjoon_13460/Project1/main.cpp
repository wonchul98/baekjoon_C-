#include<iostream>
#include<queue>

using namespace std;
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

char garray[10][10];
int visitedarr[10][10] = {0,};
int flag = 0;
int bluecol;
int bluerow;
int redcol;
int redrow;
int CNT = 1;
queue<pair<int, int>> Q;

void printarray(char array[10][10], int N, int M);
void BSF();
bool visited(int a, int b);

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
				visitedarr[i][j] = 1;
			}
		}
	}
	printarray(garray, N, M);
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
	Q.push(make_pair(redrow, redcol));
	while (!Q.empty()&&CNT<10&&!redflag) {
		bool moved = false;
		printf("CNT: %d\n", CNT);
		redrow = Q.front().first;
		redcol = Q.front().second;
		
		int saveredcol = redcol; int saveredrow = redrow;
		printf("»¡°£ °ø À§Ä¡:%d %d\n", redrow, redcol);
		Q.pop();
		cur_cnt--;
		if (garray[redrow][redcol - 1] != '#' && !visited(redrow, redcol - 1)) {
			while (garray[redrow][redcol - 1] != '#' && !visited(redrow, redcol - 1)) {
				if (garray[redrow][redcol - 1] == 'O') { redflag = true; cout << "founded" << endl; break; }
				if (garray[bluerow][bluecol - 1] == 'O') { blueflag = true; continue; }
				redcol--;
				if (garray[bluerow][bluecol-1] != '#') bluecol--;
				visitedarr[redrow][redcol] = 1;
				printf("visited (%d,%d)\n", redrow, redcol);

			}
			if (blueflag) continue;
			Q.push(make_pair(redrow, redcol));
			next_cnt++;
			redcol = saveredcol; redrow = saveredrow;
		}

		if (garray[redrow][redcol + 1] != '#' && !visited(redrow, redcol + 1)) {
			while (garray[redrow][redcol + 1] != '#' && !visited(redrow, redcol + 1)) {
				if (garray[redrow][redcol + 1] == 'O') { redflag = true; break; cout << "founded" << endl;}
				redcol++;
				visitedarr[redrow][redcol] = 1;
				printf("visited (%d,%d)\n", redrow, redcol);
			}
			Q.push(make_pair(redrow, redcol));
			next_cnt++;
			redcol = saveredcol; redrow = saveredrow;
		}

		if (garray[redrow - 1][redcol] != '#' && !visited(redrow - 1, redcol)) {
			while (garray[redrow - 1][redcol] != '#' && !visited(redrow - 1, redcol)) {
				if (garray[redrow - 1][redcol] == 'O') { redflag = true; break; cout << "founded" << endl;}
				redrow--;
				visitedarr[redrow][redcol] = 1;
				printf("visited (%d,%d)\n", redrow, redcol);
			}
			Q.push(make_pair(redrow, redcol));
			next_cnt++;
			redcol = saveredcol; redrow = saveredrow;
		}
		if (garray[redrow + 1][redcol] != '#' && !visited(redrow + 1, redcol)) {
			while (garray[redrow + 1][redcol] != '#' && !visited(redrow + 1, redcol)) {
				if (garray[redrow + 1][redcol] == 'O') { redflag = true; break; cout << "founded" << endl;}
				redrow++;
				visitedarr[redrow][redcol] = 1;
				printf("visited (%d,%d)\n", redrow, redcol);
			}
			
			Q.push(make_pair(redrow, redcol));
			next_cnt++;
			redcol = saveredcol; redrow = saveredrow;
		}
		if (redflag) break;
		cout << "cur_cnt: " << cur_cnt << " next_cnt: " << next_cnt << endl;
		if (cur_cnt == 0) {
			cout << "CNT++" << endl;
			CNT++;
			cur_cnt = next_cnt;
			next_cnt = 0;
		}
		
	}
	
}

bool visited(int a, int b) {
	if (visitedarr[a][b] == 1) return true;
	else return false;
}