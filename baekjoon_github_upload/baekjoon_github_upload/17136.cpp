#include<iostream>

using namespace std;

int map[10][10];
int visited[10][10] = { 0, };
void bigger(int a, int b);
int cnt[5] = { 5, 5,5,5,5};
int ans = 0;
bool flag = false;

int main() {
	int input;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> input;
			map[i][j] = input;
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j]&& !visited[i][j]) { bigger(i, j); }
			if (flag) {
				cout << "-1" << endl;
				return 0;
			}
		}
	}
	cout << ans << endl;
}

void bigger(int a, int b) {
	cout << "bigger: " << a << " " << b << endl;
	int save_i;
	bool flag2 = false;
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j <= i; j++) {
			if (!map[a + j][b + i]  || !map[a+i][b+j]) { //하나라도 다르다면
				flag2 = true;
				save_i = i - 1;
				cnt[save_i]--;
				ans++;
				if (cnt[save_i] < 0) flag = true;
				break;
			}
		}
		if (flag2) break;
	}
	cout << "save_i: " << save_i << endl;
	for (int i = 0; i <= save_i; i++) {
		for (int j = 0; j <= save_i; j++) {
			visited[a+i][b+j] = 1;
		}
	}
}