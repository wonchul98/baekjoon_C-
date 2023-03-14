#include<iostream>

using namespace std;

char map[3100][5300];

void draw(int size, int height, int len);

int main() {
	int s;
	cin >> s;
	draw(s, s, s);
	for (int i = s; i > 0; i--) {
		for (int j = s; j > 0; j--) {
			cout << map[i][j];
		}
		cout << endl;
	}

	return 0;
}

void draw(int size, int height, int len) {
	printf("draw(%d, %d, %d)\n", size, height, len);
	if (size == 3) {
		map[height][len] = '*';
		map[height - 1][len - 1] = '*';
		map[height - 1][len + 1] = '*';
		for (int i = 0; i < 5; i++) {
			map[height - 2][len - 2 + i] = '*';
		}
	}
	else {
		draw(size / 2, height, len);
		draw(size / 2, height - size / 2, len - size / 2);
		draw(size / 2, height - size / 2, len + size / 2);
	}
}