#define _CRT_SECURE_NO_WARNINGS	
#include<iostream>
using namespace std;

int main() {
	int T, N, M;
	//freopen("input/9084_input.txt","r", stdin);
	cin >> T;
	for (int i = 0; i < T; i++) {
		int dp[10001] = { 0, };
		dp[0] = 1;
		cin >> N;
		int coin[20] = { 0, };
		for (int j = 0;j < N; j++) {
			cin >> coin[j];
		}
		cin >> M;
		for (int j = 0; j < N; j++) {
			for (int k = coin[j]; k <= M; k++) {
				dp[k] += dp[k - coin[j]];
				//cout << "dp[" << k << "]: " << dp[k] << endl;
			}
		}
		cout << dp[M]<<endl;
	}
	return 0;
}