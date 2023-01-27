#include<iostream>

using namespace std;

int dp[1001][1001] = {0,};
int main() {
	int N, K;
	cin >> N >> K;
	if ((N + 1) / 2 < K) { cout << "0"; return 0; }
	for (int i = 1; i <= N; i++) {dp[i][0] = 1; dp[i][1] = i;}
	//if (K <= 1) { cout << dp[N][K]; return 0; }
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= K; j++) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % 1000000003;
		}
	}
	cout << (dp[N-1][K] + dp[N-3][K-1]) % 1000000003 << endl;
	
	/*if (K == 2) dp[N][K]--;
	if(N>4&&K>2) dp[N][K] -= dp[N - 4][K - 2];
	cout << dp[N][K];*/
	return 0;
}
