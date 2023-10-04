#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct INFO {
	int r, c, s;
	bool operator<(const INFO& other) const {
		if (r != other.r) return r < other.r;
		if (c != other.c) return c < other.c;
		return s < other.s;
	}
};

void rotate(INFO i);
int map[50][50];
int new_map[50][50];
void copy();
int N, M, K;
int calc();
bool print = true;
void print_map();

vector<INFO> v;
int main() {
	cin >> N >> M >> K;
	int min_rst = 987654321;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		INFO input;
		input.r = r;
		input.c = c;
		input.s = s;
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	do {
		copy();
		for (const auto& cur : v) {
			rotate(cur);
			if(print) print_map();
		}
		int rst = calc();
		min_rst = min(min_rst, rst);
	} while (next_permutation(v.begin(), v.end()));
	cout << min_rst << endl;

	return 0;
}

void copy() {
	for (int j = 0; j < N; j++) {
		for (int k = 0; k < M; k++) {
			new_map[j][k] = map[j][k];
		}
	}
}

void rotate(INFO i) {
	if (print) printf("rotate(%d, %d, %d)\n", i.r, i.c, i.s);
	int r = i.r - 1;  // 1-based 인덱스를 0-based 인덱스로 변경
	int c = i.c - 1;
	int s = i.s;

	for (int layer = 1; layer <= s; layer++) {
		int tmp = new_map[r - layer][c - layer];

		// 위쪽 이동
		for (int i = r - layer; i < r + layer; i++)
			new_map[i][c - layer] = new_map[i + 1][c - layer];

		// 왼쪽 이동
		for (int i = c - layer; i < c + layer; i++)
			new_map[r + layer][i] = new_map[r + layer][i + 1];

		// 아래쪽 이동
		for (int i = r + layer; i > r - layer; i--)
			new_map[i][c + layer] = new_map[i - 1][c + layer];

		// 오른쪽 이동
		for (int i = c + layer; i > c - layer; i--)
			new_map[r - layer][i] = new_map[r - layer][i - 1];

		new_map[r - layer][c - layer + 1] = tmp;  // 원래 첫 원소를 옮겨준다.
	}
}

int calc() {
	int min_hap = 987654321;
	for (int i = 0; i < N; i++) {
		int hap = 0;
		for (int j = 0; j < M; j++) {
			hap += new_map[i][j];
		}
		min_hap = min(hap, min_hap);
	}
	return min_hap;
}

void print_map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout.width(3);
			cout << new_map[i][j];
		}
		cout << "\n";
	}
	cout << "------------------------------" << endl;
}