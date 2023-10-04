#include<iostream>

using namespace std;

int map[5][5];
bool check_map[5][5];

int check();


int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}
	int save = 0;
	for (int i = 0; i < 25; i++) {
		int input;
		cin >> input;
		save = i;
		for (int j = 0; j < 5; j++) {
			bool flag = false;
			for (int k = 0; k < 5; k++) {
				if (map[j][k] == input) {
					check_map[j][k] = true;
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		if (check() >= 3) break;
	}
	cout << save + 1 << endl;
	return 0;
}

int check() {
	int cnt=0;
	for (int i = 0; i < 5; i++) {
		bool row = true;
		for (int j = 0; j < 5; j++) {
			if (!check_map[i][j]) {
				row = false;
				break;
			}
		}
		if (row) cnt++;
	}
	for (int i = 0; i < 5; i++) {
		bool col = true;
		for (int j = 0; j < 5; j++) {
			if (!check_map[j][i]) {
				col = false;
				break;
			}
		}
		if (col) cnt++;
	}
	bool d1 = true;
	for (int i = 0; i < 5; i++) {
		
		int j1 = i;
		if (!check_map[i][j1]) {
			d1 = false;
			break;
		}
		
	}
	if (d1) cnt++;
	bool d2 = true;
	for (int i = 0; i < 5; i++) {
		
		int j2 = 4-i;
		if (!check_map[i][j2]) {
			d2 = false;
			break;
		}
		
	}
	if (d2) cnt++;
	return cnt;
}