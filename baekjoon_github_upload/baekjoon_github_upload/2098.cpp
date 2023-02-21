#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<bitset>
#include<algorithm>
using namespace std;
#define INF 987654321
int N;
int map[17][17];
int dp[17][1 << 16];
int dp_f(bitset<17>vi, bitset<17> A);
int min_cost = INF;

int main() {
	freopen("input/2098_input.txt", "r", stdin);
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	bitset <17> first((1<<N)-2);
	cout << dp_f(1, first) << endl;
	return 0;
}

int dp_f(bitset<17>vi, bitset<17> A) {
	cout << "dp_f: " << vi << " " << A << endl;
	int minimum = INF;
	int i;
	for (int k = 0; k < N; k++) {
		if (vi.test(k)) {
			i = k + 1;
		}
	}
	if (dp[i][(int)A.to_ulong()]!=-1) return dp[i][(int)A.to_ulong()];
	if (A == 0) {
		cout << "zero" << endl;
		cout << "return of dp_f: " << vi << " " << A << ": " << map[i][1] << endl;
		if (map[i][1]!=0)return map[i][1];
		return INF;
	}
	cout << "i: " << i << endl; //vi구하기
	for (int j = 0; j < N; j++) {
		if (A.test(j)) {
			bitset<17>vj(1 << j);
			cout << "A:" << A << " j(경유지) : " << j+1 << " vj : " << vj << endl;
			bitset<17> A_vj(A & ~vj);
			cout << "j갔다가 갈 곳들: " << A_vj << endl;
			if (map[i][j + 1] > minimum) return INF;
			int rst = dp_f(vj, A_vj);
			dp[j+1][(int)A_vj.to_ulong()] = rst;
			minimum = min(minimum, map[i][j+1]+ rst);
			cout << "so rst: " << rst << " map: " << map[i][j + 1] << " minimum: " << minimum << endl;
			cout << "rst + map: " << map[i][j + 1] + rst << endl;
		}
	}
	cout << "return of dp_f: " << vi << " " << A <<": " << minimum << endl;
	return minimum;
}