#include<iostream>

using namespace std;

int dp[10001][4] = { 0, };
int T;
void make_dp();
int main() {
	cin >> T;
	make_dp();
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << dp[n][3] << endl;
	}
}

void make_dp() {
	dp[0][2] = dp[0][3] = dp[1][2] = dp[1][3] = 1;
	for (int i = 0; i <= 10000; i++) {
		dp[i][1] = 1;
	}
	for (int i = 2; i <= 10000; i++) {
		for(int j = 2;j<=3;j++){
			if (j == 2)dp[i][j] = dp[i - 2][j] + dp[i - 1][j - 1];
			else dp[i][j] = dp[i - 3][j] + dp[i - 2][j - 1] + dp[i - 1][j - 2];
		}
	}
}