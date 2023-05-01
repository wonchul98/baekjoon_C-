#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
bool print = false;
int MAX = 0, N;
int arr[21][21] = { 0, };
void dfs(int n, int d);
bool moving(int n , int d);
int main() {
	freopen("input/12100_input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			MAX = max(MAX, arr[i][j]);
		}
	}
	for (int i = 0; i < 4; i++) {
		dfs(1, i);
	}
	cout << MAX << endl;
	return 0;
}
void dfs(int n, int d) {
	if (print) {
		printf("dfs(%d, %d)\n", n, d);
		if (d == 0)cout << "←" << endl;
		if (d == 1)cout << "→" << endl;
		if (d == 2)cout << "↓" << endl;
		if (d == 3)cout << "↑" << endl;
	}
	if (n > 5) return;
	bool move = false;
	int save[21][21];
	int s = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			save[i][j] = arr[i][j];
		}
	}
	if (print) {
		cout << "======start======" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
	}
	/*연산*/
	move = moving(n, d);
	/*연산*/

	if (print) {
		cout << "======result======" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
	}
	if (!move) {
		//cout << "not moved" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = save[i][j];
			}
		}
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			dfs(n + 1, i);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = save[i][j];
			}
		}
	}
}

bool moving(int n, int d) {
	int cur_max = 0;
	bool zero = false, move = false;
	if (d == 0) {
		for (int i = 0; i < N; i++) {
			zero = false;
			int k = 0, s = 0;
			for (int j = 0; j < N; j++) {
				if (!arr[i][j]) {
					zero = true;
				}
				else if(j != N - 1) {
					if (zero) move = true;
					
					if (!s) {
						s = arr[i][j];
					}
					else if (arr[i][j] != s) {
						s = arr[i][j];
						arr[i][k++] = arr[i][j - 1];
						cur_max = max(arr[i][j - 1], cur_max);
					}
					else {//s is not empty and s == arr[i][j]
						arr[i][k++] = s * 2;
						cur_max = max(s * 2, cur_max);
						MAX = max(MAX, s * 2);
						if (!move) move = true;
						s = 0;
					}
				}
				if(j == N-1) {
					if (!s) {
						arr[i][k++] = arr[i][j];
						cur_max = max(arr[i][j], cur_max);
					}
					if (s && arr[i][j] == s) {
						arr[i][k++] = s * 2;
						cur_max = max(s*2, cur_max);
					}
					else if (s && arr[i][j] != s) {
						arr[i][k++] = s;
						arr[i][k++] = arr[i][j];
						cur_max = max(s, cur_max);
						cur_max = max(arr[i][j], cur_max);
					}
					while (k < N) {
						arr[i][k++] = 0;
					}
				}
			}
		}
	}
	if (d == 1) {
		for (int i = 0; i < N; i++) {
			int k = N-1, s = 0;
			zero = false;
			for (int j = N - 1; j >= 0; j--) {
				if (!arr[i][j]) zero = true;
				else if(j != 0) {
					if (zero) move = true;
					if (!s) {
						s = arr[i][j];
					}
					else if (arr[i][j] != s) {
						s = arr[i][j];
						arr[i][k--] = arr[i][j + 1];
						cur_max = max(arr[i][j + 1], cur_max);
					}
					else {//s is not empty and s == arr[i][j]
						arr[i][k--] = s * 2;
						cur_max = max(s * 2, cur_max);
						MAX = max(MAX, s * 2);
						if (!move) move = true;
						s = 0;
					}
				}
				if(j == 0) {
					if (!s) {
						arr[i][k--] = arr[i][j];
						cur_max = max(arr[i][j], cur_max);
					}
					if (s && arr[i][j] == s) {
						arr[i][k--] = s * 2;
						cur_max = max(s * 2, cur_max);
					}
					else if (s && arr[i][j] != s) {
						arr[i][k--] = s;
						arr[i][k--] = arr[i][j];
						cur_max = max(s, cur_max);
						cur_max = max(arr[i][j], cur_max);
					}
					while (k >= 0) {
						arr[i][k--] = 0;
					}
				}
			}
		}
	}
	if (d == 2) {
		for (int i = 0; i < N; i++) {
			int k = N - 1, s = 0;
			zero = false;
			for (int j = N - 1; j >= 0; j--) {
				if (!arr[j][i]) zero = true;
				else if(j != 0) {
					if (zero) move = true;

					if (!s) {
						s = arr[j][i];
					}
					else if (arr[j][i] != s) {
						s = arr[j][i];
						arr[k--][i] = arr[j + 1][i];
						cur_max = max(arr[j+1][i], cur_max);
					}
					else {//s is not empty and s == arr[i][j]
						arr[k--][i] = s * 2;
						cur_max = max(s * 2, cur_max);
						MAX = max(MAX, s * 2);
						if (!move) move = true;
						s = 0;
					}
				}
				if (j == 0) {
					if (!s) arr[k--][i] = arr[j][i];
					if (s && arr[j][i] == s) arr[k--][i] = s * 2;
					else if (s && arr[j][i] != s) {
						arr[k--][i] = s;
						arr[k--][i] = arr[j][i];
						cur_max = max(arr[j][i], cur_max);
						cur_max = max(s, cur_max);
					}
					while (k >= 0) {
						arr[k--][i] = 0;
					}
				}
			}
		}
	}
	if (d == 3) {
		for (int i = 0; i < N; i++) {
			int k = 0, s = 0;
			zero = false;
			for (int j = 0; j < N; j++) {
				if (!arr[j][i]) zero = true;
				else if(j != N - 1) {
					if (zero) move = true;
					if (!s) {
						s = arr[j][i];
					}
					else if (arr[j][i] != s) {
						s = arr[j][i];
						arr[k++][i] = arr[j - 1][i];
						cur_max = max(arr[j - 1][i], cur_max);
					}
					else {//s is not empty and s == arr[i][j]
						arr[k++][i] = s * 2;
						cur_max = max(s * 2, cur_max);
						MAX = max(MAX, s * 2);
						if (!move) move = true;
						s = 0;
					}
				}
				if(j == N-1) {
					if (!s) arr[k++][i] = arr[j][i];
					if (s && arr[j][i] == s) arr[k++][i] = s * 2;
					else if (s && arr[j][i] != s) {
						arr[k++][i] = s;
						arr[k++][i] = arr[j][i];
						cur_max = max(s, cur_max);
						cur_max = max(arr[j][i], cur_max);
					}
					while (k < N) {
						arr[k++][i] = 0;
					}
				}
			}
		}
	}
	if (print) cout << "move: " << move << endl;
	if (move) {
		if (cur_max * pow(2, N - n) <= MAX) {
			move = false;
		}
	}
 	return move;
}