#include<iostream>

using namespace std;

char display[397][397];

void RF(int n, int row, int col) {

}

void drawSquare(int len, int row, int col) {
	for (int i = 0; i < len; i++) {
		if (i == 0 || i == len - 1) {
			for (int j = 0; j < len; j++) {
				cout << display[row + i][col + j];
			}
		}
	}
}

int main() {
	
	int n;
	cin >> n;
	int len = 1 + 4 * (n - 1);
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			display[i][j] = ' ';
		}
	}
	return 0;
}