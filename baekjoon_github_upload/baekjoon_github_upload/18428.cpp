#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
char map[7][7];
vector<pair<int,int>> v;
bool check(int r1, int c1, int r2, int c2, int r3, int c3);
bool found(int r, int c);
int N;
bool print = false;


int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			char input;
			cin >> input;
			if (input == 'T') {
				v.push_back(make_pair(i, j));
			}
			map[i][j] = input;
		}
	}
	int N2 = N * N;
	int row1, row2, row3, col1, col2, col3;
	for (int i = 1; i <= N2-2; i++) {
		row1 = i / N + 1;
		col1 = i - (row1-1) * N + 1;
		
		if (map[row1][col1] == 'S' || map[row1][col1] == 'T') continue;
		for (int j = i + 1; j <= N2 - 1; j++) {
			row2 = j / N + 1;
			col2 = j - (row2-1) * N + 1;
			
			if (map[row2][col2] == 'S' || map[row2][col2] == 'T') continue;
			for (int k = j + 1; k <= N2; k++) {
				row3 = k / N + 1;
				col3 = k - (row3-1) * N + 1;
				if (print)cout << " ===================== " << endl;
				if (print)cout << row1 << " " << col1 << endl;
				if (print)cout << row2 << " " << col2 << endl;
				if (print)cout << row3 << " " << col3 << endl;
				if (map[row3][col3] == 'S' || map[row3][col3] == 'T') continue;
				if (!check(row1, col1, row2, col2, row3, col3)) {
					if (print)cout << "first: " << row1 << " " << col1 << endl;
					if (print)cout << "second: " << row2 << " " << col2 << endl;
					if (print)cout << "third: " << row3 << " " << col3 << endl;
					cout << "YES" << endl;
					return 0;
				}
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}


bool check(int r1, int c1, int r2, int c2, int r3, int c3) {
	map[r1][c1] = 'O';
	map[r2][c2] = 'O';
	map[r3][c3] = 'O';
	for (auto& T_loc : v) {
		if (found(T_loc.first, T_loc.second)) {
			map[r1][c1] = 'X';
			map[r2][c2] = 'X';
			map[r3][c3] = 'X';
			return true;
		}
	}
	map[r1][c1] = 'X';
	map[r2][c2] = 'X';
	map[r3][c3] = 'X';
	return false;
}

bool found(int r, int c) {
	if (print)cout << "found: " << r << " " << c << endl;
	for (int i = 0; i < 4; i++) {
		if (print)cout << "i: " << i << endl;
		int nx = r;
		int ny = c;
		while (true) {
			nx += dx[i];
			ny += dy[i];
			if (print)cout << "nx: " << nx << " ny: " << ny << endl;
			if (nx < 1 || nx > N || ny < 1 || ny > N || map[nx][ny] == 'T' || map[nx][ny] == 'O') break;
			if (map[nx][ny] == 'S') return true;
		}
	}
	return false;
}