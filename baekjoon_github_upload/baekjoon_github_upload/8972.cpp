#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int R, C, X = 0;
char map[100][100];
int dx[10] = { 0, -1, 0, 1, -1, 0, 1, -1, 0, 1 };
int dy[10] = { 0, 1, 1, 1, 0, 0, 0, -1, -1, -1 };
struct coord{
	int x, y;
};
coord js;
vector<coord> Rs;
void R_move();
bool flag = false;
void print_map();
bool print = false;
int main() {
	cin >> R >> C;
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'I') {
				js.x = j;
				js.y = i;
			}
			if (map[i][j] == 'R') {
				Rs.push_back({ j, i });
				
			}
		}
	}
	string input;
	cin >> input;
	for(int i = 0; i < input.length();i++) {
		if (flag) break;
		if (print) {
			cout << "dx: " << dx[int(input[i] - '0')] << endl;
			cout << "dy: " << dy[int(input[i] - '0')] << endl;
		}
		js.x += dx[int(input[i]-'0')];
		js.y += dy[int(input[i] - '0')];
		if (print) {
			cout << "x: " << js.x << endl;
			cout << "y: " << js.y << endl;
		}
		for (int j = 0; j < Rs.size(); j++) {
			if (js.x == Rs[j].x && js.y == Rs[j].y) {
				X++;
				flag = true;
				break;
			}
		}
		if (flag) break;
		R_move();
		if (print) print_map();
	}
	if (flag) cout << "kraj " << X << endl;
	else print_map();
	return 0;
}

void R_move(){
	vector<int> idx;
	stack<int> next_map[100][100];
	
	for (int i = 0; i < Rs.size(); i++) {
		int Rx = Rs[i].x;
		int Ry = Rs[i].y;
		if (print) cout << "Rx: " << Rx << " Ry: " << Ry << endl;
		if (Rx < js.x && Ry > js.y) {
			Rs[i].x += dx[9];
			Rs[i].y += dy[9];
		}
		else if (Rx == js.x && Ry > js.y) {
			Rs[i].x += dx[8];
			Rs[i].y += dy[8];
		}
		else if (Rx > js.x && Ry > js.y) {
			Rs[i].x += dx[7];
			Rs[i].y += dy[7];
		}
		else if (Rx < js.x && Ry == js.y) {
			Rs[i].x += dx[6];
			Rs[i].y += dy[6];
		}
		else if (Rx == js.x && Ry == js.y) {
			Rs[i].x += dx[5];
			Rs[i].y += dy[5];
		}
		else if (Rx > js.x && Ry == js.y) {
			Rs[i].x += dx[4];
			Rs[i].y += dy[4];
		}
		else if (Rx < js.x && Ry < js.y) {
			Rs[i].x += dx[3];
			Rs[i].y += dy[3];
		}
		else if (Rx == js.x && Ry < js.y) {
			Rs[i].x += dx[2];
			Rs[i].y += dy[2];
		}
		else {
			Rs[i].x += dx[1];
			Rs[i].y += dy[1];
		}
		
		if (Rs[i].x == js.x && Rs[i].y == js.y) {
			X++;
			flag = true;
			return;
		}
		next_map[Rs[i].y][Rs[i].x].push(i);
		if (print) printf("push %d into (%d, %d)\n", i, Rs[i].x, Rs[i].y);
		
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) { 
			if (next_map[i][j].size() > 1) {
				while (!next_map[i][j].empty()) {
					if (print) printf("삭제 리스트 push: %d\n", next_map[i][j].top());
					idx.push_back(next_map[i][j].top());
					next_map[i][j].pop();
				}
			}
		}
	}
	sort(idx.begin(), idx.end(), greater<int>());
	for (int i = 0; i < idx.size(); i++) {
		if (print)printf("erase: (%d, %d), idx: %d\n",Rs[idx[i]].x, Rs[idx[i]].y, idx[i]);
		if (print)printf("size: %d\n", Rs.size());
		if (print) printf("%d\n", Rs[idx[i]].x);
		Rs.erase(Rs.begin() + idx[i]);
	}
	X++;
}

void print_map() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[j][i] = '.';
		}
	}
	map[js.x][js.y] = 'I';
	for (int i = 0; i < Rs.size(); i++) {
		map[Rs[i].x][Rs[i].y] = 'R';
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[j][i];
		}
		cout << "\n";
	}
}