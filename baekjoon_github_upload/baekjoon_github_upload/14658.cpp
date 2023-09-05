#include<iostream>
#include<vector>

using namespace std;
int N, M, L, K;

struct INFO {
	int x, y;
};
vector<INFO> v;

int calc(int x, int y);
int main() {
	cin >> N >> M >> L >> K;
	for (int i = 0; i < K; i++) {
		INFO input;
		cin >> input.x >> input.y;
		v.push_back(input);
	}
	int ans = 0;
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			ans = max(ans, calc(v[i].x, v[j].y));
		}
	}
	cout << K - ans << endl;
	return 0;
}

int calc(int x, int y) {
	int cnt=0;
	for (int i = 0; i < K; i++) {
		if (v[i].x >= x && v[i].x <= x + L && v[i].y >= y && v[i].y <= y + L) cnt++;
	}
	return cnt;
}