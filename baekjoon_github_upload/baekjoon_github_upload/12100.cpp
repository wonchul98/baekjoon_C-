#include<iostream>
#include<vector>
using namespace std;

int MAX, N;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int arr[20][20] = { 0, };
void dfs(int n, int d);
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		dfs(0, i);
	}
	cout << MAX << endl;
	return 0;
}
void dfs(int n, int d) {
	if (n > 5) return;
	bool move = false;
	int save[20][20];
	int front, s=0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; i < N; i++) {
			save[i][j] = arr[i][j];
		}
	}

	/*연산*/
	for (int i = 0; i < N; i++) {
		/*d에 따라사 now_v생성*/
		vector<int> now_v;
		if (d == 0) {
			for (int j = 0; j < N; j++) {
				if (!arr[i][j]) now_v.push_back(arr[i][j]);
			}
		}
		if (d == 1) {
			for (int j = N - 1; j >= 0; j--) {
				if (!arr[i][j]) now_v.push_back(arr[i][j]);
			}
		}
		if (d == 2) {
			for (int j = N - 1; j >= 0; j--) {
				if (!arr[j][i]) now_v.push_back(arr[j][i]);
			}
		}
		if (d == 3) {
			for (int j = 0; j < N; j--) {
				if (!arr[j][i]) now_v.push_back(arr[j][i]);
			}
		}
		while (!now_v.empty()) {/*벡터가 비어 있는 상태로 들어가도 잘 작동하는지 확인*/
			if (s) {//s가 비어있지 않은 경우
				if()
			}
		}
	}
	/*연산*/

	if (!move) return;
	else {
		for (int i = 0; i < 4; i++) {
			dfs(n+1, i);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = save[i][j];
			}
		}
	}
}
