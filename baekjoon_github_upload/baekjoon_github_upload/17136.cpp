#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>

using namespace std;

int max_size = 0;

int size_map[10][10] = { 0, };
int map[10][10] = { 0, };
int visited[10][10] = { 0, };
int cnt[6] = { 0, 5,5,5,5,5 };
int ans = 0;
int min_ans = 987654321;
bool flag = false;
int bigger(int a, int b);
void attach(int a, int b, int size);
void detach(int a, int b, int size);
void dfs();
bool fill();

int main() {
	freopen("17136_input/input.txt", "r", stdin);
	int input;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> input;
			map[i][j] = input;
		}
	}
	if (fill()) {
		cout << "0" << endl;
		return 0;
	}
	dfs();
	if (flag)cout << min_ans << endl;
	else cout << "-1" << endl;
}

int bigger(int a, int b) { //색종이의 최대 사이즈 리턴
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= i; j++) {
			if (!map[a + j][b + i] ||visited[a+j][b+i] || !map[a+i][b+j] || visited[a+i][b+j]) { //하나라도 다르다면
				return i; //i는 size임
			}
		}
	}
}

void attach(int a, int b, int size) {
	ans++;
	cnt[size]--;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			visited[a + i][b + j] = 1;
		}
	}
}

void detach(int a, int b, int size) {
	ans--;
	cnt[size]++;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			visited[a + i][b + j] = 0;
		}
	}
}

void dfs() {
	if (min_ans < ans) return;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] && !visited[i][j]) {
				int able = bigger(i,j);
				while(1){
					if (cnt[able] >= 1 && able > 0) {//붙일 색종이가 있다면
						//cout << "i: " << i << " j: " << j << " able: " << able << endl;
						attach(i, j, able); //해당 위치에 색종이 붙임
						//cout << "cnt: ";
						for (int i = 1; i < 6; i++) {
							//cout << cnt[i] << " ";
						}
						//cout << endl;
						if (fill()) {
							flag = true;
							//cout << "filled" << endl;
							min_ans = min(min_ans, ans);
						}
						
						dfs();
						detach(i, j, able);//리턴이 됐다면 땐다
					}
					able--;//사이즈 줄임
					if (able == 0) {
						//cout << "back_tracking" << endl;
						return; // 붙일 수 있는 색종이가 없는 경우 리턴
					}
				}
			}
		}
	}
}

bool fill() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] && !visited[i][j]) {
				//printf("%d, %d is not filled yet\n", i, j);
				return false;
			}
		}
	}
	return true;
}