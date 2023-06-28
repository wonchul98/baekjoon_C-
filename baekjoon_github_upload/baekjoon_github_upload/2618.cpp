#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
using namespace std;
struct COORD {
	int x;
	int y;
};
int N, W;
int min_dist[1001][1001];
int dist(int a, int b);
void path(int a, int b);
int make_dp(int A, int B);
void solution();
COORD event[1001];
stack<int> S;
bool print = false;
int main() {
	freopen("input/2618_input.txt", "r", stdin);
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			min_dist[i][j] = -1;
		}
	}
	cin >> N >> W;
	for (int i = 1; i <= W; i++) {
		cin >> event[i].x >> event[i].y;
	}
	solution();
	return 0;
}

int dist(int a, int b) {
	//printf("dist(%d, %d)\n", a, b);
	//cout << event[a].x << " " << event[b].x << " " << event[a].y << " " << event[b].y << endl;
 	return abs(event[a].x - event[b].x) + abs(event[a].y - event[b].y);
}

int make_dp(int A, int B) {
	if(print) printf("make_dp(%d, %d)\n", A, B);
	if (min_dist[A][B] != -1) return min_dist[A][B];
	if (A == W || B == W) return 0;
	int next_e;
	
	int dist_1, dist_2;
	next_e = max(A, B) + 1;
	if (A == 0) dist_1 = abs(1 - event[next_e].x) + abs(1 - event[next_e].y);
	else dist_1 = dist(A, next_e);
	if (B == 0) dist_2 = abs(N - event[next_e].x) + abs(N - event[next_e].y);
	else dist_2 = dist(B, next_e);
	if (print) printf("dist_1: %d, dist_2: %d\n", dist_1, dist_2);
	int rst1, rst2;
	rst1 = dist_1 + make_dp(next_e, B);
	rst2 = dist_2 + make_dp(A, next_e);
	if (print) printf("rst1: %d, rst2: %d\n", rst1, rst2);
	int p = rst1 < rst2 ? 1 : 2;
	min_dist[A][B] = min(rst1, rst2);
	return min_dist[A][B];
}
void path(int a, int b) {
	if (print) printf("path(%d, %d)\n", a, b);
	if (a == W || b == W) return;
	int dist_1, dist_2;
	int next_e = max(a, b) + 1;
	if (a == 0) dist_1 = abs(1 - event[next_e].x) + abs(1 - event[next_e].y);
	else dist_1 = dist(a, next_e);
	if (b == 0) dist_2 = abs(N - event[next_e].x) + abs(N - event[next_e].y);
	else dist_2 = dist(b, next_e);
	if (print) printf("dist_1: %d, dist_2: %d\n", dist_1, dist_2);
	int rst1, rst2;
	rst1 = dist_1 + min_dist[next_e][b];
	rst2 = dist_2 + min_dist[a][next_e];
	if (rst1 < rst2) {
		cout << "1" << endl;
		path(next_e, b);
	}
	else {
		cout << "2" << endl;
		path(a, next_e);
	}
}
void solution() {
	int a = 0, b = 0;
	make_dp(0, 0);
	cout << min_dist[0][0] << endl;
	path(0, 0);
}