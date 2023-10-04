#include<iostream>
using namespace std;
int N, M;
int map[700][700];
int save[1400];
int main() {
	cin >> N >> M;

	for (int i = 0; i < 2 * N; i++) save[i] = 1;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = a; j < a + b; j++) {
			save[j] += 1;
		}
		for (int j = a + b; j < a + b + c; j++) {
			save[j] += 2;
		}
	}
	//for (int i = 0; i < 2 * N - 1; i++) cout << save[i] << " ";
	for (int i = 0; i < N; i++) {
		map[N - 1 - i][0] = save[i]; //0~N-1
	}
	for (int i = 1; i < N; i++) {
		map[0][i] = save[N - 1 + i]; //N ~ 2N-2
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			map[i][j] = max(map[i - 1][j - 1], max(map[i - 1][j], map[i][j - 1]));
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}