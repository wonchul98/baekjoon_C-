#include <iostream>
#include <vector>
using namespace std;
struct INFO {
	int T, turn;
};
int N, K;
int map[100][100] = { 0, }; // 사과는 2 지렁이는 1 나머지 0
vector<INFO> v;
int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int R, C;
		cin >> R >> C;
		map[R][C] = 2;
	}
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		INFO push;
		cin >> push.T >> push.turn;
		v.push_back(push);
	}
	while (!v.empty()) {

	}
	return 0;
}