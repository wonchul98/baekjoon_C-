#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool print = false;
int MAX = 0, N;
int arr[21][21] = { 0, };
void dfs(int n, int d);
int main() {
	//freopen("input/12100_input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		dfs(1, i);
	}
	cout << MAX << endl;
	return 0;
}
void dfs(int n, int d) {
	//printf("dfs(%d, %d)\n", n, d);
	//if (d == 0)cout << "←" << endl;
	//if (d == 1)cout << "→" << endl;
	//if (d == 2)cout << "↓" << endl;
	//if (d == 3)cout << "↑" << endl;
	if (n > 5) return;
	bool move = false;
	int save[21][21];
	int front, s=0;
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
	for (int i = 0; i < N; i++) {
		bool zero = false;
		/*d에 따라서 now_v생성*/
		vector<int> now_v;
		if (d == 0) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j]) { now_v.push_back(arr[i][j]); if (zero) move = true; }
				else if (!zero) zero = true;
			}
		}
		if (d == 1) {
			for (int j = N - 1; j >= 0; j--) {
				if (arr[i][j]) { now_v.push_back(arr[i][j]); if (zero) move = true; }
				else if (!zero) zero = true;
			}
		}
		if (d == 2) {
			for (int j = N - 1; j >= 0; j--) {
				if (arr[j][i]) { now_v.push_back(arr[j][i]); if (zero) move = true; }
				else if (!zero) zero = true;
			}
		}
		if (d == 3) {
			for (int j = 0; j < N; j++) {
				if (arr[j][i]) { 
					now_v.push_back(arr[j][i]); 
					if (zero) move = true;
				}
				else if (!zero) zero = true;
			}
		}
		//now_v 출력
		s = 0;
		for (int j = 0; j < now_v.size(); j++) {
			if (!s) { //s가 0이면
				s = now_v[j];
			}
			else {
				if (now_v[j] == s) {
					now_v[j - 1] = 0;
					now_v[j] = 2 * s;
					s = 0;
					move = true;
				}
				else {
					s = now_v[j];
				}
			}
		}

		for (int j = 0; j < now_v.size(); j++) {
			if (!now_v[j]) now_v.erase(now_v.begin() + j);
		}
		if (now_v.size()) {
			for (int j = 0; j < now_v.size(); j++) {
				if (MAX < now_v[j]) {
					MAX = now_v[j];
					//cout << "changed" << endl;
				}
				if (d == 0) {
					arr[i][j] = now_v[j];
				}
				if (d == 1) {
					arr[i][N-j-1] = now_v[j];

				}
				if (d == 2) {
					arr[N-j-1][i] = now_v[j];
				}
				if (d == 3) {
					arr[j][i] = now_v[j];
				}
			}
			for (int j = now_v.size(); j < N; j++) {
				if (d == 0) {
					arr[i][j] = 0;
				}
				if (d == 1) {
					arr[i][N - j - 1] = 0;
				}
				if (d == 2) {
					arr[N - j - 1][i] = 0;
				}
				if (d == 3) {
					arr[j][i] = 0;
				}
			}
		}
	}
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
			dfs(n+1, i);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = save[i][j];
			}
		}
	}
}
