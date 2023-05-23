#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int T;
bool print = false;
int dp[22][4] = { 0, };
void makedp(int a);
int main() {
	freopen("input/2718_input.txt", "r", stdin);
	cin >> T;
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 0;
	dp[1][3] = 0;
	dp[2][0] = 5;
	dp[2][1] = 2;
	dp[2][2] = 3;
	dp[2][3] = 1;
	for (int i = 3; i < 22; i++) {
		makedp(i);
	}
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		cout << dp[N][0] << endl;
	}
	return 0;
}

void makedp(int a) {
	dp[a][1] = dp[a - 1][0] + dp[a - 1][1];
	dp[a][3] = dp[a - 2][3] + dp[a - 2][0];
	dp[a][2] = dp[a - 2][0] + dp[a - 1][1] + dp[a][3];
	dp[a][0] = dp[a][1] + dp[a][2];
	if(print) cout << dp[a][0] << " " << dp[a][1] << " " << dp[a][2] << " " << dp[a][3] << endl;
}