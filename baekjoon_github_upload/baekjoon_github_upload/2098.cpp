#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<bitset>
#include<algorithm>
#include<cstring>
using namespace std;
#define INF 987654321
int N;
int map[17][17];
int dp[17][1 << 16];
int dp_f(bitset<17>vi, bitset<17> A);
int min_cost = INF;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input/2098_input.txt", "r", stdin);
	cin >> N;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	bitset<17> first((1<<N)-2);
	bitset<17> va(0b1);
	cout << dp_f(va, first) << endl;
	return 0;
}

int dp_f(bitset<17>vi, bitset<17> A) {
	int minimum = INF;
	int i;
	for (int k = 0; k < N; k++) {
		if (vi.test(k)) {
			i = k + 1;
		}
	}
	int ret = dp[i][A.to_ulong()];
	if (ret != -1) return ret;
	if (A == 0) { //마지막 방문
		if (map[i][1] != 0) {
			return map[i][1];
		}
		return INF;
	}
	
	for (int j = 0; j < N; j++) {
		if (A.test(j)) {
			bitset<17>vj(1 << j);
			bitset<17> A_vj(A & ~vj);
			if (map[i][j + 1] > minimum) continue;
			int rst = dp_f(vj, A_vj);
			if(map[i][j+1]!=0)minimum = min(minimum, map[i][j+1]+ rst);
		}
	}
	dp[i][A.to_ulong()] = minimum;
	return minimum;
}