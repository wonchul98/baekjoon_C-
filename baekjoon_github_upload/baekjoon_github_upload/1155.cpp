#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;
long long dp[31][3][3] = {0,};
int N;
char prior[6][3];
int main() {
	freopen("input/1155_input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < 6; i++) {
		cin >> prior[i];
		prior[i][0] -= 'A';
		prior[i][1] -= 'A';
	}
	for (int i = 0; i < 6; i++) {
		int from = prior[i][0], to = prior[i][1];
		if (!dp[1][from][0] && !dp[1][from][1] && !dp[1][from][2]) dp[1][from][to] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int from = 0; from < 3; from++) {
			for (int to = 0; to < 3; to++) {
				if (from != to) {
					if (dp[i-1][from][3 - from - to] && dp[i-1][3 - from - to][to]) dp[i][from][to] = dp[i-1][from][3 - from - to] + 1 + dp[i-1][3 - from - to][to];
					else if (dp[i-1][from][to] && dp[i-1][to][from]) dp[i][from][to] = 2 * dp[i-1][from][to] + dp[i-1][to][from] + 2;
				}
			}
		}
	}
	printf("%lld", dp[N][0][1] ? dp[N][0][1] : dp[N][0][2]);

	return 0;
}