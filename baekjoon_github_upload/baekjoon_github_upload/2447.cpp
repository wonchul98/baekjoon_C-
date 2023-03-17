#include<iostream>
using namespace std;

char map[2200][2200];
void draw(int size, int height, int len);
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = ' ';
		}
	}
	draw(n, n, (n + 1) / 2);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}

void draw(int size, int height, int len) {
	//printf("draw(%d,%d,%d)\n", size, height, len);
	if (size == 1) {
		map[height][len] = '*';
	}
	else {
		int new_size = size / 3;
		for (int i = -1; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				// << "i: " << i << "j: " << j << endl;
				if (i != 0 || j != 1) {
					draw(new_size, height - new_size * j, len + i * new_size);
				}
			}
		}
	}
}